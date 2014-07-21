#include "BaseBinaryReader.h"

class NationLaw : public BaseBinaryReader
{
public:
    NationLaw() {}

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
            r->ReadStringArray("string array");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadIntArray("int array");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};