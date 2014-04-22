#include "BaseBinaryReader.h"

class FightChallenge : public BaseBinaryReader
{
public:
    FightChallenge() {}

    QString GetColumns()
    {
        return QString("int|int|string|int|int|int|int|bool|int array|int array|int");
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
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadBool();
            d << r->ReadIntArray();
            d << r->ReadIntArray();
            d << r->ReadInt();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
