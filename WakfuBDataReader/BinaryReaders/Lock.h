#include "BaseBinaryReader.h"

class Lock : public BaseBinaryReader
{
public:
    Lock() {}

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
            r->ReadLong("long");
            r->ReadLong("long");
            r->ReadBool("bool");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};