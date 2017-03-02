#include "BaseBinaryReader.h"

struct AlmanachEntryBinaryData
{
    qint32 m_id;
    qint32 m_scenarioId;
    qint32 m_achievementId;
    QList<qint32> m_territories;
};

class AlmanachEntry : public BaseBinaryReader
{
public:
    AlmanachEntry() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            AlmanachEntryBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_scenarioId = r->ReadInt("m_scenarioId");
            entry.m_achievementId = r->ReadInt("m_achievementId");
            entry.m_territories = r->ReadIntArray("m_territories");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};