#include "BaseBinaryReader.h"

struct ClimateBonusListBinaryData
{
    qint32 m_buffListId;
    QList<qint32> m_entries;
};

class ClimateBonusList : public BaseBinaryReader
{
public:
    ClimateBonusList() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            ClimateBonusListBinaryData entry;

            entry.m_buffListId = r->ReadInt("m_buffListId");
            entry.m_entries = r->ReadIntArray("m_entries");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};