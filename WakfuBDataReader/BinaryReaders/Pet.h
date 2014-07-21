#include "BaseBinaryReader.h"

class Pet : public BaseBinaryReader
{
public:
    Pet() {}

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
            r->ReadInt("int");
            r->ReadLong("long");
            r->ReadLong("long");
            r->ReadByte("byte");
            r->ReadShort("short");
            r->ReadShort("short");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadIntArray("int array");
            r->ReadInt("int");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};