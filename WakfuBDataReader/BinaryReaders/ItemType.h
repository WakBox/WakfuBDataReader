#include "BaseBinaryReader.h"

class ItemType : public BaseBinaryReader
{
public:
    ItemType() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            // Struct
            r->ReadShort("short");
            r->ReadShort("short");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadStringArray("string array");
            r->ReadStringArray("string array");
            r->ReadShort("short");
            r->ReadIntArray("int array");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};