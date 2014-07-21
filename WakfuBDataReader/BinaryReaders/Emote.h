#include "BaseBinaryReader.h"

class Emote : public BaseBinaryReader
{
public:
    Emote() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            // Struct
            r->ReadInt("Emote ID");
            r->ReadShort("Type"); // type 1 = normal, type 2 = need a target ?
            r->ReadString("Name");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadStringArray("string array");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};
