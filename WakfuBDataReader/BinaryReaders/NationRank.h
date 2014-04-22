#include "BaseBinaryReader.h"

class NationRank : public BaseBinaryReader
{
public:
    NationRank() {}

    QString GetColumns()
    {
        return QString("int|float|string|int");
    }

    void Read(Rows rows)
    {
        qint32 size = rows.size();
        qDebug() << size;

        for (qint32 i = 0; i < 1; ++i)
        {
            Row row = rows[i];
            QVariantList d;

            r->SetBufferPosition(row.offset);

            // Struct
            d << r->ReadInt();
            d << r->ReadFloat();

            qint32 strSize = r->ReadInt();
            qDebug() << strSize;
            d << r->ReadString(strSize);

            d << r->ReadInt();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
