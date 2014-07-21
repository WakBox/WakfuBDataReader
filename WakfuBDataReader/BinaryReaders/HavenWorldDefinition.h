#include "BaseBinaryReader.h"

class HavenWorldDefinition : public BaseBinaryReader
{
public:
    HavenWorldDefinition() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            // Struct
            r->ReadInt("int");
            r->ReadShort("short");
            r->ReadByte("byte");
            r->ReadShort("short");
            r->ReadShort("short");
            r->ReadShort("short");
            r->ReadShort("short");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};