#include "BaseBinaryReader.h"

class Achievement : public BaseBinaryReader
{
public:
    Achievement() {}

    QString GetColumns()
    {
        return QString("int|int|bool|bool|bool|string|int|int|int|int|bool|bool|bool|int|int|bool|int|long|long|bool|int|byte");
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
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadString();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadBool();
            d << r->ReadInt();
            d << r->ReadLong();
            d << r->ReadLong();
            d << r->ReadBool();
            d << r->ReadInt();
            d << r->ReadByte();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
