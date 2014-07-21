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
        if (m_entries.size() > m_cols.size())
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
    T Read(QString name = "unk")
    {
        CalcHoo();

        T v;
        *this >> v;
        v = v - m_hoo;

        if (!name.isEmpty())
            AddEntry((name != "unk") ? name : name + " " + QString::number(m_col++), v);

        return v;
    }

    float ReadFloat(QString name = "unk")
    {
        CalcHoo();
        float v;
        *this >> v;

        if (!name.isEmpty())
            AddEntry((name != "unk") ? name : name + " " + QString::number(m_col++), v);

        return v;
    }

    bool ReadBool(QString name = "unk") { return Read<bool>(name); }
    qint32 ReadInt(QString name = "unk") { return Read<qint32>(name); }
    quint32 ReadUInt(QString name = "unk") { return Read<quint32>(name); }
    double ReadDouble(QString name = "unk") { return Read<double>(name); }
    qint16 ReadShort(QString name = "unk") { return Read<qint16>(name); }
    quint16 ReadUShort(QString name = "unk") { return Read<quint16>(name); }
    char ReadByte(QString name = "unk"){ return Read<qint8>(name); }
    uchar ReadUByte(QString name = "unk") { return Read<quint8>(name); }
    qint64 ReadLong(QString name = "unk") { return Read<qint64>(name); }
    quint64 ReadULong(QString name = "unk") { return Read<quint64>(name); }

    void ReadBytes(char*& s, uint len)
    {
        m_stream.readBytes(s, len);
    }

    void ReadRawBytes(char* s, int len)
    {
        m_stream.readRawData(s, len);
    }

    QString ReadString(QString name = "unk")
    {
        quint32 len = ReadInt(QString());

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
            AddEntry((name != "unk") ? name : name + " " + QString::number(m_col++), str);

        return str;
    }

    void ReadStringArray(QString name = "unk")
    {
        qint32 size = ReadInt(QString());

        for (quint16 i = 0; i < size; ++i)
            ReadString(((name != "unk") ? name : name + " " + QString::number(m_col++)) + " [" + QString::number(i) + "]");
    }

    // Y'a un problème avec les floats...
    // Voir si incompatibilité Java <-> Qt ??
    void ReadFloatArray(QString name = "unk")
    {
        qint32 size = ReadInt(QString());

        for (quint16 i = 0; i < size; ++i)
            ReadFloat(name + " [" + QString::number(i) + "]");
    }

    template <typename T>
    void ReadArray(QString name = "unk")
    {
        quint32 size = ReadInt(QString());

        for (quint16 i = 0; i < size; ++i)
            Read<T>(name + " [" + QString::number(i) + "]");
    }

    void ReadByteArray(QString name = "unk") { ReadArray<qint8>(name); }
    void ReadIntArray(QString name = "unk") { ReadArray<qint32>(name); }
    void ReadShortArray(QString name = "unk") { ReadArray<qint16>(name); }
    void ReadLongArray(QString name = "unk") { ReadArray<qint64>(name); }

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
