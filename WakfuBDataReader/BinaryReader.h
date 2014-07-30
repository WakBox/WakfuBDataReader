#ifndef BINARYREADER_H
#define BINARYREADER_H

#include <QtCore>

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
        m_columns = QString();
        m_firstRow = false;
    }

    void FirstRow(bool first = true)
    {
        m_firstRow = first;
    }

    void AddColumnName(QString name)
    {
        if (m_firstRow && !name.isEmpty())
        {
            if (m_columns.isEmpty())
                m_columns = name;
            else
                m_columns += "|" + name;
        }
    }

    QString GetColumns()
    {
        return m_columns;
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

    template <class T>
    BinaryReader& operator>>(T& value)
    {
        m_stream >> value;
        return *this;
    }

    template <typename T>
    T Read(QString name)
    {
        AddColumnName(name);
        CalcHoo();

        T v;
        *this >> v;

        return v - m_hoo;
    }

    float ReadFloat(QString name = "float")
    {
        AddColumnName(name);
        CalcHoo();

        float v;
        *this >> v;

        return v;
    }

    bool ReadBool(QString name = "bool") { return Read<bool>(name); }
    qint32 ReadInt(QString name = "int") { return Read<qint32>(name); }
    quint32 ReadUInt(QString name = "uint") { return Read<quint32>(name); }
    double ReadDouble(QString name = "double") { return Read<double>(name); }
    qint16 ReadShort(QString name = "short") { return Read<qint16>(name); }
    quint16 ReadUShort(QString name = "ushort") { return Read<quint16>(name); }
    char ReadByte(QString name = "byte"){ return Read<qint8>(name); }
    uchar ReadUByte(QString name = "ubyte") { return Read<quint8>(name); }
    qint64 ReadLong(QString name = "long") { return Read<qint64>(name); }
    quint64 ReadULong(QString name = "ulong") { return Read<quint64>(name); }

    void ReadBytes(char*& s, uint len)
    {
        m_stream.readBytes(s, len);
    }

    void ReadRawBytes(char* s, int len)
    {
        m_stream.readRawData(s, len);
    }

    QString ReadString(QString name = "string")
    {
        AddColumnName(name);
        quint32 len = ReadInt(QString());

        QByteArray bytes;
        bytes.resize(len);

        for (quint32 i = 0; i < len; ++i)
        {
            qint8 v;
            *this >> v;
            bytes[i] = v;
        }

        return QString::fromUtf8(bytes);
    }

    QString ReadStringArray(QString name = "string array")
    {
        AddColumnName(name);
        QString result = "[";

        quint32 size = ReadInt(QString());

        for (quint16 i = 0; i < size; ++i)
            result += ReadString(QString()) + ", ";

        return result.remove(result.size(), -2) + "]";
    }

    QString ReadFloatArray(QString name = "float array")
    {
        AddColumnName(name);
        QString result = "[";

        quint32 size = ReadInt(QString());

        for (quint16 i = 0; i < size; ++i)
            result += QString::number(ReadFloat(QString())) + ", ";

        return result.remove(result.size(), -2) + "]";
    }

    template <typename T>
    QString ReadArray(QString name)
    {
        AddColumnName(name);
        QString result = "[";

        quint32 size = ReadInt(QString());

        for (quint16 i = 0; i < size; ++i)
        {
            T v = Read<T>(QString());

            result += QString::number(v);

            if (i != size - 1)
                result += ", ";
        }

        result += "]";
        return result;
    }

    QString ReadByteArray(QString name = "byte array") { return ReadArray<qint8>(name); }
    QString ReadIntArray(QString name = "int array") { return ReadArray<qint32>(name); }
    QString ReadShortArray(QString name = "short array") { return ReadArray<qint16>(name); }
    QString ReadLongArray(QString name = "long array") { return ReadArray<qint64>(name); }

    QByteArray ReadAllFromCurrentPos() { return m_stream.device()->readAll(); }
    qint32 GetSize() { return m_size; }

private:
    QByteArray m_buffer;
    QDataStream m_stream;

    int m_fileId;
    qint32 m_size;
    qint8 m_hoo;

    bool m_firstRow;
    QString m_columns;
};

#endif // BINARYREADER_H
