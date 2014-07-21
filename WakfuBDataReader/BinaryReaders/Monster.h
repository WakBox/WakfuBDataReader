#include "BaseBinaryReader.h"

class Monster : public BaseBinaryReader
{
public:
    Monster() {}

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
            r->ReadFloat("float");
            r->ReadFloat("float");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
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
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
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
            r->ReadFloat("float");
            r->ReadFloat("float");
            r->ReadFloat("float");
            r->ReadFloat("float");
            r->ReadBool("bool");
            r->ReadShort("short");
            r->ReadShort("short");
            r->ReadShort("short");
            r->ReadInt("int");
            r->ReadIntArray("int array");
            r->ReadIntArray("int array");
            r->ReadShortArray("short array");
            r->ReadInt("int");
            r->ReadByte("byte");
            r->ReadShort("short");
            r->ReadShort("short");
            r->ReadShort("short");
            r->ReadShort("short");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadShort("short");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadIntArray("int array");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};