#include "BaseBinaryReader.h"

struct GemAndPowderBinaryData
{
    qint32 m_id;
};

class GemAndPowder : public BaseBinaryReader
{
public:
    GemAndPowder() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            GemAndPowderBinaryData entry;

            entry.m_id = r->ReadInt("m_id");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};