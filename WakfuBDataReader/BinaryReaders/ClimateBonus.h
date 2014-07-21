#include "BaseBinaryReader.h"

class ClimateBonus : public BaseBinaryReader
{
public:
    ClimateBonus() {}

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
            r->ReadString("string");
            r->ReadInt("int");
            r->ReadShort("short");
            r->ReadFloat("float");
            r->ReadFloat("float");
            r->ReadFloat("float");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};