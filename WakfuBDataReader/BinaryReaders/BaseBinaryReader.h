#ifndef BASEBINARYREADER_H
#define BASEBINARYREADER_H

#include "BinaryReader.h"

class BaseBinaryReader : public QObject
{
    Q_OBJECT

public:
    BaseBinaryReader(QObject* parent = 0) : QObject(parent) {}
    virtual ~BaseBinaryReader()
    {
        if (r)
        {
            delete r;
            r = NULL;
        }
    }

    void Open(QByteArray buffer, quint8 fileId, qint32 fileSize)
    {
        r = new BinaryReader(buffer, fileId, fileSize);
    }

    virtual void Read(Rows rows) = 0;

signals:
    void Finished(Entry cols, DataRow rows);

protected:
    BinaryReader* r;
};

#endif // BASEBINARYREADER_H
