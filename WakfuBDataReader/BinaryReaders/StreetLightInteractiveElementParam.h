#include "BaseBinaryReader.h"

class StreetLightInteractiveElementParam : public BaseBinaryReader
{
public:
    StreetLightInteractiveElementParam() {}

    QString GetColumns()
    {
        return QString("int|int|float|int|bool|int|bool|int|int|bool|int");
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
            d << r->ReadInt();
            d << r->ReadFloat();
            d << r->ReadInt();
            d << r->ReadBool();
            d << r->ReadInt();
            d << r->ReadBool();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadBool();
            d << r->ReadInt();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
