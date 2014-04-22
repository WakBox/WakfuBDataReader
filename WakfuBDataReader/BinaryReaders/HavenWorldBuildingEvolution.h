#include "BaseBinaryReader.h"

class HavenWorldBuildingEvolution : public BaseBinaryReader
{
public:
    HavenWorldBuildingEvolution() {}

    QString GetColumns()
    {
        return QString("int|short|int|int|long|byte");
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
            d << r->ReadLong();
            d << r->ReadByte();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
