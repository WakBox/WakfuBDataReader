#include "BaseBinaryReader.h"

class Skill : public BaseBinaryReader
{
public:
    Skill() {}

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
            r->ReadInt("int");
            r->ReadString("string");
            r->ReadString("string");
            r->ReadIntArray("int array");
            r->ReadIntArray("int array");
            r->ReadInt("int");
            r->ReadBool("bool");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};