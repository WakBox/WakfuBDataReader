#include "BaseBinaryReader.h"

class Tutorial : public BaseBinaryReader
{
public:
    Tutorial() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            // Struct
            r->ReadInt("ID");

            qint32 size = r->ReadInt(QString());
            for (quint32 i = 0; i < size; ++i)
                r->ReadInt("int");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};
