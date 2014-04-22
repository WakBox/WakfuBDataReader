#include "BaseBinaryReader.h"

class InteractiveElementModel : public BaseBinaryReader
{
public:
    InteractiveElementModel() {}

    QString GetColumns()
    {
        return QString("viewId|type|gfx|color|height|unkInt|unkInt");
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
            d << r->ReadShort();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadByte();
            d << r->ReadInt();
            d << r->ReadInt();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
