#include "BaseBinaryReader.h"

struct InstanceInteractionLevelBinaryData
{
    qint32 m_id;
    qint32 m_worldId;
    qint32 m_subscriptionLevel;
    qint32 m_interactionLevel;
};

class InstanceInteractionLevel : public BaseBinaryReader
{
public:
    InstanceInteractionLevel() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            InstanceInteractionLevelBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_worldId = r->ReadInt("m_worldId");
            entry.m_subscriptionLevel = r->ReadInt("m_subscriptionLevel");
            entry.m_interactionLevel = r->ReadInt("m_interactionLevel");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};