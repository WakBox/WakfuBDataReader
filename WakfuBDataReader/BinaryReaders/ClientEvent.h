#include "BaseBinaryReader.h"

class ClientEvent : public BaseBinaryReader
{
public:
    ClientEvent() {}

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
            r->ReadString("string");
            r->ReadStringArray("string array");
            r->ReadBool("bool");
            r->ReadInt("int");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};