#include "BaseBinaryReader.h"

class ItemSet : public BaseBinaryReader
{
public:
    ItemSet() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            // Struct
            r->ReadShort("short");
            r->ReadInt("int");
            r->ReadIntArray("int array");

            qint32 size = r->ReadInt(QString());
            for (quint32 i = 0; i < size; ++i)
            {
                r->ReadInt("int");
                r->ReadIntArray("int array");
            }

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};
