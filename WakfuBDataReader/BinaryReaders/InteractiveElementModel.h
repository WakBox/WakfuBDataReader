#include "BaseBinaryReader.h"

class InteractiveElementModel : public BaseBinaryReader
{
public:
    InteractiveElementModel() {}

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
            d << r->ReadInt("ViewId");
            d << r->ReadShort("Type");
            d << r->ReadInt("GFX");
            d << r->ReadInt("Color");
            d << r->ReadByte("Height");
            d << r->ReadInt();
            d << r->ReadInt();

            data.push_back(d);
            r->FirstRow(false);
        }

        emit Finished(data);
    }
};
