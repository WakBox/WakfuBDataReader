#include "BaseBinaryReader.h"

class Resource : public BaseBinaryReader
{
public:
    Resource() {}

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
            r->ReadShort("short");
            r->ReadShort("short");
            r->ReadShort("short");
            r->ReadShort("short");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadShort("short");
            r->ReadIntArray("int array");
            r->ReadIntArray("int array");
            r->ReadInt("int");
            r->ReadShort("short");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadIntArray("int array");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};