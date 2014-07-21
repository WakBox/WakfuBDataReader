#include "BaseBinaryReader.h"

class Recipe : public BaseBinaryReader
{
public:
    Recipe() {}

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
            r->ReadLong("long");
            r->ReadString("string");
            r->ReadString("string");
            r->ReadInt("int");
            r->ReadIntArray("int array");
            r->ReadInt("int");
            r->ReadIntArray("int array");
            r->ReadInt("int");
            r->ReadBool("bool");
            r->ReadLong("long");
            r->ReadLong("long");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};