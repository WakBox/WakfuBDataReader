#include "BaseBinaryReader.h"

class RewardDisplayerInteractiveElementParam : public BaseBinaryReader
{
public:
    RewardDisplayerInteractiveElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            // Struct
            r->ReadInt("int");
            r->ReadIntArray("int array");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};