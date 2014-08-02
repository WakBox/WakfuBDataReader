#include "BaseBinaryReader.h"

class Emote : public BaseBinaryReader
{
public:
    Emote() {}

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
            d << r->ReadInt("Emote Id");
            d << r->ReadShort("Type (1 = normal, 2 = need a target ?)");
            d << r->ReadString("Name");
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadStringArray();

            data.push_back(d);
            r->FirstRow(false);
        }

        emit Finished(data);
    }
};
