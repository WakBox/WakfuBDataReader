#include "BaseBinaryReader.h"

class Item : public BaseBinaryReader
{
public:
    Item() {}

    QString GetColumns()
    {
        return r->GetColumns();
    }

    void Read(Rows rows)
    {
        qint32 size = rows.size();
        r->FirstRow();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            QVariantList d;

            r->SetBufferPosition(row.offset);

            // Struct
            d << r->ReadInt("Item Id");
            d << r->ReadInt("Parent Item Id ?");
            d << r->ReadShort("Item set");
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadShort("Item level");
            d << r->ReadStringArray("Conditions");
            d << r->ReadInt("Slot Id (Item type)");
            d << r->ReadShort("Stackable");
            d << r->ReadByte("Action Point cost");
            d << r->ReadByte();
            d << r->ReadByte();
            d << r->ReadInt("Min range");
            d << r->ReadInt("Max range");
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

            quint32 size = r->ReadInt();
            for (quint32 i = 0; i < size; ++i)
            {
                d << r->ReadInt();
                d << r->ReadInt();
                d << r->ReadBool();
                d << r->ReadBool();
                d << r->ReadBool();
                d << r->ReadBool();
                d << r->ReadString();
                d << r->ReadStringArray();
                d << r->ReadStringArray();
            }

            d << r->ReadIntArray();
            d << r->ReadByteArray();
            d << r->ReadByteArray();

            data.push_back(d);
            r->FirstRow(false);
        }

        emit Finished(data);
    }
};
