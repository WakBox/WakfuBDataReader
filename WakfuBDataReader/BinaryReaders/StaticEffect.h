#include "BaseBinaryReader.h"

class StaticEffect : public BaseBinaryReader
{
public:
    StaticEffect() {}

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
            r->ReadIntArray("int array");
            r->ReadShort("short");
            r->ReadShort("short");
            r->ReadIntArray("int array");
            r->ReadShort("short");
            r->ReadIntArray("int array");
            r->ReadIntArray("int array");
            r->ReadIntArray("int array");
            r->ReadIntArray("int array");
            r->ReadIntArray("int array");
            r->ReadIntArray("int array");
            r->ReadIntArray("int array");
            r->ReadString("string");
            r->ReadLongArray("long array");
            r->ReadBool("bool");
            r->ReadInt("int");
            r->ReadFloat("float");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadShort("short");
            r->ReadFloat("float");
            r->ReadFloatArray("float array");
            r->ReadFloat("float");
            r->ReadFloat("float");
            r->ReadByte("byte");
            r->ReadByte("byte");
            r->ReadByte("byte");
            r->ReadBool("bool");
            r->ReadShort("short");
            r->ReadFloat("float");
            r->ReadByte("byte");
            r->ReadBool("bool");
            r->ReadString("string");
            r->ReadShort("short");
            r->ReadShort("short");
            r->ReadString("string");
            r->ReadString("string");
            r->ReadString("string");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadInt("int");
            r->ReadBool("bool");
            r->ReadIntArray("int array");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};