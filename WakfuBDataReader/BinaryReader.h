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
    }

    void SetBufferPosition(qint64 pos)
    {
        m_stream.device()->seek(pos);
    }

    void SetHoo(qint8 hoo)
    {
        m_hoo = hoo;
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
        m_hoo = (qint8)(qint32)(m_hoo + (m_fileId * (m_stream.device()->pos()) + m_size));

        T v;
        *this >> v;

        return v - m_hoo;
    }

    bool ReadBool() { return Read<bool>(); }
    qint32 ReadInt() { return Read<qint32>(); }
    quint32 ReadUInt() { return Read<quint32>(); }

    // LE FLOAT est différent !
    /*
    public float getFloat()
    {
        this.akU();
        return this.bmp.getFloat();
    }
    */
    float ReadFloat() { return Read<float>(); }
    double ReadDouble() { return Read<double>(); }
    qint16 ReadShort() { return Read<qint16>(); }
    quint16 ReadUShort() { return Read<quint16>(); }
    char ReadByte(){ return Read<qint8>(); }
    uchar ReadUByte() { return Read<quint8>(); }
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

    QString ReadString(qint32 len)
    {
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

    QByteArray ReadAllFromCurrentPos() { return m_stream.device()->readAll(); }
    qint32 GetSize() { return m_size; }

private:
    QByteArray m_buffer;
    QDataStream m_stream;

    int m_fileId;
    qint32 m_size;
    qint8 m_hoo;
};

#endif // BINARYREADER_H
