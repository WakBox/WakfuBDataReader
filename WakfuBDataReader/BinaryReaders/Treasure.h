#include "BaseBinaryReader.h"

class Treasure : public BaseBinaryReader
{
public:
    Treasure() {}

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
            r->ReadInt("int");
            r->ReadShort("short");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadString("string");
            r->ReadFloat("float");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};