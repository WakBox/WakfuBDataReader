#include "BaseBinaryReader.h"

class CharacGainPerLevel : public BaseBinaryReader
{
public:
    CharacGainPerLevel() {}

    QString GetColumns()
    {
        return QString("short|int|byte|float");
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
            d << r->ReadShort();
            d << r->ReadInt();
            d << r->ReadByte();
            d << r->ReadFloat();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
