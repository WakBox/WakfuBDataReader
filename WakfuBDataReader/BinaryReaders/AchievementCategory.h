#include "BaseBinaryReader.h"

class AchievementCategory : public BaseBinaryReader
{
public:
    AchievementCategory() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            // Struct
            r->ReadInt("ID categorie");
            r->ReadInt("Categorie parente");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};
