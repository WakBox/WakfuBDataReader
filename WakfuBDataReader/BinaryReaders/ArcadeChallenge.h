#include "BaseBinaryReader.h"

class ArcadeChallenge : public BaseBinaryReader
{
public:
    ArcadeChallenge() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            // Struct
            r->ReadInt("ID");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};
