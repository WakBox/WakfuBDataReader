#include "BaseBinaryReader.h"

class MonsterType : public BaseBinaryReader
{
public:
    MonsterType() {}

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
            d << r->ReadInt("Type Id");
            d << r->ReadInt("Parent type Id");
            d << r->ReadByte();

            data.push_back(d);
            r->FirstRow(false);
        }

        emit Finished(data);
    }
};
