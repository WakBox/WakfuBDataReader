#include "BaseBinaryReader.h"

struct AlmanachDateBinaryData
{
    qint32 m_id;
    qint64 m_date;
    qint32 m_almanachEntryId;
};

class AlmanachDate : public BaseBinaryReader
{
public:
    AlmanachDate() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            AlmanachDateBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_date = r->ReadLong("m_date");
            entry.m_almanachEntryId = r->ReadInt("m_almanachEntryId");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};