#include "BaseBinaryReader.h"

class AlmanachEntry : public BaseBinaryReader
{
public:
    AlmanachEntry() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            // Struct
            r->ReadInt("ID");
            r->ReadInt("int");
            r->ReadInt("Quest?");
            r->ReadIntArray("int array");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};
