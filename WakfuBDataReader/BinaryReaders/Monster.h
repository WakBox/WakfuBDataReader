#include "BaseBinaryReader.h"

class Monster : public BaseBinaryReader
{
public:
    Monster() {}

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
            d << r->ReadInt("Monster Id");
            d << r->ReadInt();
            d << r->ReadShort("Level");
            d << r->ReadShort();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadInt("HP");
            d << r->ReadInt("Wakfu points");
            d << r->ReadInt("AP points");
            d << r->ReadInt("MP points");
            d << r->ReadInt();
            d << r->ReadInt("Initiative");
            d << r->ReadInt("Perception");
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt("Critical hit");
            d << r->ReadInt();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt("Fire Damage ?");
            d << r->ReadInt("Water Damage ?");
            d << r->ReadInt("Earth Damage");
            d << r->ReadInt("Air Damage ?");
            d << r->ReadInt("Fire Resist");
            d << r->ReadInt("Water Resist");
            d << r->ReadInt("Earth Resist ?");
            d << r->ReadInt("Air Resist ?");
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadBool();
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadInt();
            d << r->ReadIntArray();
            d << r->ReadIntArray();
            d << r->ReadShortArray();

            qint32 size = r->ReadInt(QString());

            for (qint32 i = 0; i < size; ++i)
            {
                d << r->ReadInt("Id");
                d << r->ReadInt("Level");
            }

            d << r->ReadByte();
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadShort();

            size = r->ReadInt(QString());
            for (qint32 i = 0; i < size; ++i)
            {
                d << r->ReadInt();
                d << r->ReadByte();
                d << r->ReadString();
                d << r->ReadBool();
                d << r->ReadBool();
                d << r->ReadInt();
                d << r->ReadBool();
                d << r->ReadInt();
                d << r->ReadInt();
            }

            size = r->ReadInt(QString());
            for (qint32 i = 0; i < size; ++i)
            {
                d << r->ReadInt();
                d << r->ReadInt();
                d << r->ReadInt();
                d << r->ReadInt();
                d << r->ReadString();
                d << r->ReadFloat();
                d << r->ReadInt();
                d << r->ReadInt();
                d << r->ReadInt();
                d << r->ReadIntArray();
                d << r->ReadBool();
            }

            size = r->ReadInt(QString());
            for (qint32 i = 0; i < size; ++i)
            {
                d << r->ReadInt();
                d << r->ReadInt();
                d << r->ReadInt();
                d << r->ReadBool();
            }

            size = r->ReadInt(QString());
            for (qint32 i = 0; i < size; ++i)
            {
                d << r->ReadInt();
                d << r->ReadInt();
                d << r->ReadInt();
            }

            d << r->ReadInt();
            d << r->ReadShort();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadIntArray();

            size = r->ReadInt(QString());
            for (qint32 i = 0; i < size; ++i)
            {
                d << r->ReadString();
                d << r->ReadStringArray();
            }

            size = r->ReadInt(QString());
            for (qint32 i = 0; i < size; ++i)
            {
                d << r->ReadInt();
                d << r->ReadInt();
            }

            size = r->ReadInt(QString());
            for (qint32 i = 0; i < size; ++i)
            {
                d << r->ReadByte("AnimId ?");
                d << r->ReadString("AnimName");
            }

            d << r->ReadInt();
            d << r->ReadInt();

            data.push_back(d);
            r->FirstRow(false);
        }

        emit Finished(data);
    }
};
