#include "BaseBinaryReader.h"

class Achievement : public BaseBinaryReader
{
public:
    Achievement() {}

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
            d << r->ReadInt("Achievement Id");
            d << r->ReadInt();
            d << r->ReadBool("IsVisible");
            d << r->ReadBool();
            d << r->ReadBool("IsActive");
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
            r->FirstRow(false);
        }

        emit Finished(data);
    }
};
