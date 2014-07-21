#include "BaseBinaryReader.h"

class CharacGainPerLevel : public BaseBinaryReader
{
public:
    CharacGainPerLevel() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            // Struct
            r->ReadShort("short");
            r->ReadInt("int");
            r->ReadByte("byte");
            r->ReadFloat("float");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};