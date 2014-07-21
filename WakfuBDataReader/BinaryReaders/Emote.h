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
            r->ReadShort("Type");
            r->ReadString("Emote");
            r->ReadBool();
            r->ReadBool();
            r->ReadBool();
            r->ReadBool();
            r->ReadStringArray();

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};
