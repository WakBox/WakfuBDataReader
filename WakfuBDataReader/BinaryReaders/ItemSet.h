#include "BaseBinaryReader.h"

class ItemSet : public BaseBinaryReader
{
public:
    ItemSet() {}

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
            d << r->ReadShort("ItemSet Id");
            d << r->ReadInt();
            d << r->ReadIntArray("Items");

            qint32 size = r->ReadInt(QString());
            for (quint32 i = 0; i < size; ++i)
            {
                r->ReadInt("int");
                r->ReadIntArray("int array");
            }

            data.push_back(d);
            r->FirstRow(false);
        }

        emit Finished(data);
    }
};
