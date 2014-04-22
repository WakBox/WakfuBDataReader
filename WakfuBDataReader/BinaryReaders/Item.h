#include "BaseBinaryReader.h"

class Item : public BaseBinaryReader
{
public:
    Item() {}

    QString GetColumns()
    {
        return QString("int|int|short|int|int|int|short|string array|int|short|byte|byte|byte|int|int|bool|bool|bool|bool|short|byte|string|int array|byte|byte|byte|byte|int array|int|int array|byte array|byte array");
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
            d << r->ReadShort();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadShort();
            d << r->ReadStringArray();
            d << r->ReadInt();
            d << r->ReadShort();
            d << r->ReadByte();
            d << r->ReadByte();
            d << r->ReadByte();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadShort();
            d << r->ReadByte();
            d << r->ReadString();
            d << r->ReadIntArray();
            d << r->ReadByte();
            d << r->ReadByte();
            d << r->ReadByte();
            d << r->ReadByte();
            d << r->ReadIntArray();
            d << r->ReadInt();
            d << r->ReadIntArray();
            d << r->ReadByteArray();
            d << r->ReadByteArray();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
