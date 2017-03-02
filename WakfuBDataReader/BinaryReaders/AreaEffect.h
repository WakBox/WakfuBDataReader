#include "BaseBinaryReader.h"

struct AreaEffectBinaryData
{
    qint32 m_id;
    qint32 m_scriptId;
    qint32 m_areaAreaId;
    qint32 m_maxExecutionCount;
    qint32 m_targetsToShow;
    bool m_canBeTargeted;
    bool m_obstacleForAI;
    bool m_shouldStopMovement;
    bool m_canBeTargetedByAI;
    bool m_canBeDestroyed;
    QString m_type;
    QList<qint32> m_areaAreaParams;
    QList<qint32> m_applicationTriggers;
    QList<qint32> m_unapplicationTriggers;
    QList<qint32> m_destructionTriggers;
    QList<float> m_deactivationDelay;
    QList<float> m_params;
    QList<qint32> m_properties;
    QList<qint32> m_effectIds;
    QString m_areaGfx;
    QString m_areaCellGfx;
    QString m_aps;
    QString m_cellAps;
    qint32 m_maxLevel;
};

class AreaEffect : public BaseBinaryReader
{
public:
    AreaEffect() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            AreaEffectBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_scriptId = r->ReadInt("m_scriptId");
            entry.m_areaAreaId = r->ReadInt("m_areaAreaId");
            entry.m_maxExecutionCount = r->ReadInt("m_maxExecutionCount");
            entry.m_targetsToShow = r->ReadInt("m_targetsToShow");
            entry.m_canBeTargeted = r->ReadBool("m_canBeTargeted");
            entry.m_obstacleForAI = r->ReadBool("m_obstacleForAI");
            entry.m_shouldStopMovement = r->ReadBool("m_shouldStopMovement");
            entry.m_canBeTargetedByAI = r->ReadBool("m_canBeTargetedByAI");
            entry.m_canBeDestroyed = r->ReadBool("m_canBeDestroyed");
            entry.m_type = r->ReadString("m_type");
            entry.m_areaAreaParams = r->ReadIntArray("m_areaAreaParams");
            entry.m_applicationTriggers = r->ReadIntArray("m_applicationTriggers");
            entry.m_unapplicationTriggers = r->ReadIntArray("m_unapplicationTriggers");
            entry.m_destructionTriggers = r->ReadIntArray("m_destructionTriggers");
            entry.m_deactivationDelay = r->ReadFloatArray("m_deactivationDelay");
            entry.m_params = r->ReadFloatArray("m_params");
            entry.m_properties = r->ReadIntArray("m_properties");
            entry.m_effectIds = r->ReadIntArray("m_effectIds");
            entry.m_areaGfx = r->ReadString("m_areaGfx");
            entry.m_areaCellGfx = r->ReadString("m_areaCellGfx");
            entry.m_aps = r->ReadString("m_aps");
            entry.m_cellAps = r->ReadString("m_cellAps");
            entry.m_maxLevel = r->ReadInt("m_maxLevel");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};