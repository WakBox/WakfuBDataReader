#ifndef BASEBINARYREADER_H
#define BASEBINARYREADER_H

#include <QTreeWidget>
#include "mainwindow.h"
#include "BinaryReader.h"

class BaseBinaryReader : public QObject
{
    Q_OBJECT

public:
    BaseBinaryReader(QObject* parent = 0) : QObject(parent) {}

    void Open(QByteArray buffer, quint8 fileId, qint32 fileSize)
    {
        r = new BinaryReader(buffer, fileId, fileSize);
    }

    QVector<QVariantList> GetData() { return data; }

    virtual QString GetColumns() = 0;
    virtual void Read(Rows rows) = 0;

signals:
    void Finished(QVector<QVariantList> data);

protected:
    BinaryReader* r;
    QVector<QVariantList> data;
};

#endif // BASEBINARYREADER_H
