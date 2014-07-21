#include "BaseBinaryReader.h"

class Craft : public BaseBinaryReader
{
public:
    Craft() {}

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
            r->ReadFloat("float");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};