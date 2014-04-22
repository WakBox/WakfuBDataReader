#include "BaseBinaryReader.h"

class ItemType : public BaseBinaryReader
{
public:
    ItemType() {}

    QString GetColumns()
    {
        return QString("short|short|bool|bool|bool|string array|string array|short|int array");
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
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadStringArray();
            d << r->ReadStringArray();
            d << r->ReadShort();
            d << r->ReadIntArray();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
