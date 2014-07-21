#include "BaseBinaryReader.h"

class Spell : public BaseBinaryReader
{
public:
    Spell() {}

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
            r->ReadShort("short");
            r->ReadShort("short");
            r->ReadShort("short");
            r->ReadFloat("float");
            r->ReadShort("short");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadInt("int");
            r->ReadString("string");
            r->ReadFloat("float");
            r->ReadFloat("float");
            r->ReadFloat("float");
            r->ReadFloat("float");
            r->ReadFloat("float");
            r->ReadFloat("float");
            r->ReadFloat("float");
            r->ReadFloat("float");
            r->ReadFloat("float");
            r->ReadFloat("float");
            r->ReadShort("short");
            r->ReadShort("short");
            r->ReadShort("short");
            r->ReadShort("short");
            r->ReadShort("short");
            r->ReadString("string");
            r->ReadByte("byte");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadIntArray("int array");
            r->ReadByte("byte");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadIntArray("int array");
            r->ReadInt("int");
            r->ReadByte("byte");
            r->ReadInt("int");
            r->ReadString("string");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};