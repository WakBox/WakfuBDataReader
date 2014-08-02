#include "BaseBinaryReader.h"

class AchievementList : public BaseBinaryReader
{
public:
    AchievementList() {}

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
            d << r->ReadInt("Achievement List Id");
            quint32 size = r->ReadInt(QString());
            for (quint32 i = 0; i < size; ++i)
            {
                r->ReadInt();
                r->ReadInt("Order");
            }

            data.push_back(d);
            r->FirstRow(false);
        }

        emit Finished(data);
    }
};
