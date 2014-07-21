#include "BaseBinaryReader.h"

class RecycleMachineInteractiveElementParam : public BaseBinaryReader
{
public:
    RecycleMachineInteractiveElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            // Struct
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadByte("byte");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};