#include "BaseBinaryReader.h"

class HavenWorldBuildingCatalog : public BaseBinaryReader
{
public:
    HavenWorldBuildingCatalog() {}

    QString GetColumns()
    {
        return QString("int|int|int|int|bool|short|bool|int|int");
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
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadBool();
            d << r->ReadShort();
            d << r->ReadBool();
            d << r->ReadInt();
            d << r->ReadInt();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
