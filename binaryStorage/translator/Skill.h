#include "BaseBinaryReader.h"

class Skill : public BaseBinaryReader
{
public:
    Skill() {}

    QString GetColumns()
    {
        return QString("int|int|int|int|string|string|int array|int array|int|bool");
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
            d << r->ReadString();
            d << r->ReadString();
            d << r->ReadIntArray();
            d << r->ReadIntArray();
            d << r->ReadInt();
            d << r->ReadBool();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
