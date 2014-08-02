#include "BaseBinaryReader.h"

class Spell : public BaseBinaryReader
{
public:
    Spell() {}

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
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadFloat();
            d << r->ReadShort();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadInt();
            d << r->ReadString();
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
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadString();
            d << r->ReadByte();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadIntArray();
            d << r->ReadByte();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadIntArray();
            d << r->ReadInt();
            d << r->ReadByte();
            d << r->ReadInt();
            d << r->ReadString();

            data.push_back(d);
            r->FirstRow(false);
        }

        emit Finished(data);
    }
};
