#include "BaseBinaryReader.h"

class AreaEffect : public BaseBinaryReader
{
public:
    AreaEffect() {}

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
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadString("string");
            r->ReadIntArray("int array");
            r->ReadIntArray("int array");
            r->ReadIntArray("int array");
            r->ReadIntArray("int array");
            r->ReadFloatArray("float array");
            r->ReadFloatArray("float array");
            r->ReadIntArray("int array");
            r->ReadIntArray("int array");
            r->ReadString("string");
            r->ReadString("string");
            r->ReadString("string");
            r->ReadString("string");
            r->ReadInt("int");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};