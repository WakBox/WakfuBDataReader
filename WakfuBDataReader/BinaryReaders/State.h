#include "BaseBinaryReader.h"

class State : public BaseBinaryReader
{
public:
    State() {}

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
            r->ReadIntArray("int array");
            r->ReadIntArray("int array");
            r->ReadFloatArray("float array");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadString("string");
            r->ReadString("string");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadIntArray("int array");
            r->ReadIntArray("int array");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadByte("byte");
            r->ReadByte("byte");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadInt("int");
            r->ReadBool("bool");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};