#include "BaseBinaryReader.h"

class ClimateBonus : public BaseBinaryReader
{
public:
    ClimateBonus() {}

    QString GetColumns()
    {
        return QString("int|int|string|int|short|float|float|float");
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
            d << r->ReadString();
            d << r->ReadInt();
            d << r->ReadShort();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
