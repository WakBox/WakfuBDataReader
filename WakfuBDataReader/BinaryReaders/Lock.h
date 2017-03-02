#include "BaseBinaryReader.h"

struct LockBinaryData
{
    qint32 m_id;
    qint32 m_lockedItemId;
    qint32 m_lockValue;
    qint64 m_periodDuration;
    qint64 m_unlockDate;
    bool m_availableForCitizensOnly;
};

class Lock : public BaseBinaryReader
{
public:
    Lock() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            LockBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_lockedItemId = r->ReadInt("m_lockedItemId");
            entry.m_lockValue = r->ReadInt("m_lockValue");
            entry.m_periodDuration = r->ReadLong("m_periodDuration");
            entry.m_unlockDate = r->ReadLong("m_unlockDate");
            entry.m_availableForCitizensOnly = r->ReadBool("m_availableForCitizensOnly");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};