#ifndef BINARYREADER_H
#define BINARYREADER_H

#include <QtCore>

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
    T Read()
    {
        CalcHoo();

        T v;
        *this >> v;
        v = v - m_hoo;

        return v;
    }

    float ReadFloat()
    {
        CalcHoo();

        float v;
        *this >> v;

        return v;
    }

    bool ReadBool() { return Read<bool>(); }
    qint32 ReadInt() { return Read<qint32>(); }
    quint32 ReadUInt() { return Read<quint32>(); }
    double ReadDouble() { return Read<double>(); }
    qint16 ReadShort() { return Read<qint16>(); }
    quint16 ReadUShort() { return Read<quint16>(); }
    qint8 ReadByte(){ return Read<qint8>(); }
    quint8 ReadUByte() { return Read<quint8>(); }
    qint64 ReadLong() { return Read<qint64>(); }
    quint64 ReadULong() { return Read<quint64>(); }

    void ReadBytes(char*& s, uint len)
    {
        m_stream.readBytes(s, len);
    }

    void ReadRawBytes(char* s, int len)
    {
        m_stream.readRawData(s, len);
    }

    QString ReadString()
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
        return str;
    }

    QList<qint32> ReadIntArray()
    {
        QList<qint32> intArray;
        qint32 size = ReadInt();

        for (qint32 i = 0; i < size; ++i)
        {
            intArray.push_back(ReadInt());
        }

        return intArray;
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
