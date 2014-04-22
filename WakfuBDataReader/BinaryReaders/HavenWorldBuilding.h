#include "BaseBinaryReader.h"

class HavenWorldBuilding : public BaseBinaryReader
{
public:
    HavenWorldBuilding() {}

    QString GetColumns()
    {
        return QString("int|short|int|int|int|bool|int|int|int array|int");
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
            d << r->ReadInt();
            d << r->ReadBool();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadIntArray();
            d << r->ReadInt();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
