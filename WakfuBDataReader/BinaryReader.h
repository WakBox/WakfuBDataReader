#ifndef BINARYREADER_H
#define BINARYREADER_H

#include <QtCore>

struct Row
{
    qint64 id;
    qint32 offset;
    qint32 size;
    qint8 seed;
};

typedef QMap<int, Row> Rows;

struct sEntry
{
    QString name;
    QVariant value;
};

typedef QList<sEntry> Entry;
typedef QList<Entry> DataRow;

class BinaryReader
{
public:
    BinaryReader(QByteArray file, int fileId, int fileSize = 0) : m_buffer(file), m_stream(&m_buffer, QIODevice::ReadOnly), m_fileId(fileId), m_size(fileSize)
    {
        m_stream.setByteOrder(QDataStream::LittleEndian);
        m_stream.setFloatingPointPrecision(QDataStream::SinglePrecision);

        if (fileSize == 0)
        {
            *this >> m_size;
            m_size += 756423;
        }

        m_hoo = qint8(m_fileId ^ m_size);
        m_col = 1;
    }

    void SetBufferPosition(qint64 pos)
    {
        m_stream.device()->seek(pos);
    }

    void SetHoo(qint8 hoo)
    {
        m_hoo = hoo;
    }

    void CalcHoo()
    {
        m_hoo = (qint8)(qint32)(m_hoo + (m_fileId * (m_stream.device()->pos()) + m_size));
    }

    void AddEntry(QString name, QVariant value)
    {
        sEntry entry;
        entry.name = name;
        entry.value = value;

        m_entries.push_back(entry);
    }

    Entry GetCols()
    {
        return m_cols;
    }

    DataRow GetRows()
    {
        return m_rows;
    }

    void PushRow()
    {
        if (!m_cols.size())
            m_cols = m_entries;

        m_rows.push_back(m_entries);
        m_entries.clear();
        m_col = 1;
    }

    template <class T>
    BinaryReader& operator>>(T& value)
    {
        m_stream >> value;
        return *this;
    }

    template <typename T>
    T Read(QString name = "")
    {
        CalcHoo();

        T v;
        *this >> v;
        v = v - m_hoo;

        if (!name.isEmpty())
            AddEntry(name, v);

        return v;
    }

    float ReadFloat(QString name = "")
    {
        CalcHoo();

        float v;
        *this >> v;

        if (!name.isEmpty())
            AddEntry(name, v);

        return v;
    }

    bool ReadBool(QString name = "") { return Read<bool>(name); }
    qint32 ReadInt(QString name = "") { return Read<qint32>(name); }
    quint32 ReadUInt(QString name = "") { return Read<quint32>(name); }
    double ReadDouble(QString name = "") { return Read<double>(name); }
    qint16 ReadShort(QString name = "") { return Read<qint16>(name); }
    quint16 ReadUShort(QString name = "") { return Read<quint16>(name); }
    qint8 ReadByte(QString name = ""){ return Read<qint8>(name); }
    quint8 ReadUByte(QString name = "") { return Read<quint8>(name); }
    qint64 ReadLong(QString name = "") { return Read<qint64>(name); }
    quint64 ReadULong(QString name = "") { return Read<quint64>(name); }

    void ReadBytes(char*& s, uint len)
    {
        m_stream.readBytes(s, len);
    }

    void ReadRawBytes(char* s, int len)
    {
        m_stream.readRawData(s, len);
    }

    QString ReadString(QString name = "")
    {
        quint32 len = ReadInt();

        QByteArray bytes;
        bytes.resize(len);

        for (quint32 i = 0; i < len; ++i)
        {
            qint8 v;
            *this >> v;
            bytes[i] = v;
        }

        QString str = QString::fromUtf8(bytes);

        if (!name.isEmpty())
            AddEntry(name, str);

        return str;
    }

    QStringList ReadStringArray(QString name = "")
    {
        QStringList stringArray, v;
        qint32 size = ReadInt();

        for (qint32 i = 0; i < size; ++i)
        {
            QString value = ReadString();
            stringArray.push_back(value);
            v.push_back(value);
        }

        if (!name.isEmpty())
            AddEntry(name, v.join("|"));

        return stringArray;
    }

    QList<qint32> ReadIntArray(QString name = "")
    {
        QList<qint32> intArray;
        qint32 size = ReadInt();
        QStringList v;

        for (qint32 i = 0; i < size; ++i)
        {
            qint32 value = ReadInt();
            intArray.push_back(value);
            v.push_back(QString::number(value));
        }

        if (!name.isEmpty())
            AddEntry(name, v.join("|"));

        return intArray;
    }

    QList<float> ReadFloatArray(QString name = "")
    {
        QList<float> floatArray;
        qint32 size = ReadInt();
        QStringList v;

        for (qint32 i = 0; i < size; ++i)
        {
            float value = ReadFloat();
            floatArray.push_back(value);
            v.push_back(QString::number(value));
        }

        if (!name.isEmpty())
            AddEntry(name, v.join("|"));

        return floatArray;
    }

    QList<qint8> ReadByteArray(QString name = "")
    {
        QList<qint8> byteArray;
        qint32 size = ReadInt();
        QStringList v;

        for (qint32 i = 0; i < size; ++i)
        {
            qint8 value = ReadByte();
            byteArray.push_back(value);
            v.push_back(QString::number(value));
        }

        if (!name.isEmpty())
            AddEntry(name, v.join("|"));

        return byteArray;
    }

    QByteArray ReadAllFromCurrentPos() { return m_stream.device()->readAll(); }
    qint32 GetSize() { return m_size; }

private:
    QByteArray m_buffer;
    QDataStream m_stream;

    int m_fileId;
    qint32 m_size;
    qint8 m_hoo;

    Entry m_entries;
    Entry m_cols;
    DataRow m_rows;
    int m_col;
};

#endif // BINARYREADER_H
