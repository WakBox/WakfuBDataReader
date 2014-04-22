#include "BaseBinaryReader.h"

class Pet : public BaseBinaryReader
{
public:
    Pet() {}

    QString GetColumns()
    {
        return QString("int|int|int|int|int|long|long|short|short|int|int|int|int|int array|int");
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
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadLong();
            d << r->ReadLong();
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadIntArray();
            d << r->ReadInt();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
