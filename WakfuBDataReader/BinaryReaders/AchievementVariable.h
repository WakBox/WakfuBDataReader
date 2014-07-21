#include "BaseBinaryReader.h"

class AchievementVariable : public BaseBinaryReader
{
public:
    AchievementVariable() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            // Struct
            r->ReadInt("ID");
            r->ReadString("Name");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};
