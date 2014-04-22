#include "BaseBinaryReader.h"

class Recipe : public BaseBinaryReader
{
public:
    Recipe() {}

    QString GetColumns()
    {
        return QString("int|int|long|string|string|int|int array|int|int array|int|bool|long|long|int|int|int");
    }

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            QVariantList d;

            r->SetBufferPosition(row.offset);

            // Struct
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadLong();
            d << r->ReadString();
            d << r->ReadString();
            d << r->ReadInt();
            d << r->ReadIntArray();
            d << r->ReadInt();
            d << r->ReadIntArray();
            d << r->ReadInt();
            d << r->ReadBool();
            d << r->ReadLong();
            d << r->ReadLong();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
