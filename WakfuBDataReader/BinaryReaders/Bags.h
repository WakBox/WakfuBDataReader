#include "BaseBinaryReader.h"

class Bags : public BaseBinaryReader
{
public:
    Bags() {}

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
            d << r->ReadInt("Id");
            d << r->ReadShort("Capacity");
            d << r->ReadInt();
            d << r->ReadIntArray();

            data.push_back(d);
            r->FirstRow(false);
        }

        emit Finished(data);
    }
};
