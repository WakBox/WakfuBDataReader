#include "BaseBinaryReader.h"

class SkillAction : public BaseBinaryReader
{
public:
    SkillAction() {}

    QString GetColumns()
    {
        return QString("int|int|string|int array|string");
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
            d << r->ReadIntArray();
            d << r->ReadString();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
