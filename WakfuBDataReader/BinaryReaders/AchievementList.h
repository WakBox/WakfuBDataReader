#include "BaseBinaryReader.h"

class AchievementList : public BaseBinaryReader
{
public:
    AchievementList() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            // Struct
            r->ReadInt("ID");
            qint32 size = r->ReadInt(QString());
            for (quint32 i = 0; i < size; ++i)
            {
                r->ReadInt("int");
                r->ReadInt("Order");
            }

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};
