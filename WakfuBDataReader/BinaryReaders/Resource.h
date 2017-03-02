#include "BaseBinaryReader.h"

struct ResourceStepAction
{
    qint32 m_id;
    qint32 m_skillId;
    qint32 m_resourceNextIndex;
    qint32 m_skillLevelRequired;
    qint32 m_skillSimultaneousPlayer;
    qint32 m_skillVisualFeedbackId;
    qint32 m_duration;
    qint32 m_consumableId;
    qint32 m_gfxId;
    QString m_criteria;
    qint32 m_collectLootListId;
    qint32 m_collectItemId;
    QList<qint32> m_lootItems;
    qint32 m_mruOrder;
    bool m_displayInCraftDialog;
};

struct ResourceStep
{
    qint32 m_index;
    QList<ResourceStepAction> m_actions;
    qint32 m_sizeCategoryId;
    qint32 m_lightRadius;
    qint32 m_lightColor;
    qint32 m_apsId;
    qint32 m_apsPosZ;
};

struct ResourceBinaryData
{
    qint32 m_id;
    qint32 m_type;
    qint16 m_idealRainMin;
    qint16 m_idealRainMax;
    qint16 m_idealTemperatureMin;
    qint16 m_idealTemperatureMax;
    bool m_isBlocking;
    bool m_useBigChallengeAps;
    bool m_isMonsterEmbryo;
    qint16 m_monsterStepHatching;
    QList<qint32> m_properties;
    QList<qint32> m_monsterFamilies;
    QList<ResourceStep> m_steps;
    qint16 m_height;
    qint32 m_iconGfxId;
    QMap<qint32, QList<qint32>> m_gfxIds;
};

class Resource : public BaseBinaryReader
{
public:
    Resource() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            ResourceBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_type = r->ReadInt("m_type");
            entry.m_idealRainMin = r->ReadShort("m_idealRainMin");
            entry.m_idealRainMax = r->ReadShort("m_idealRainMax");
            entry.m_idealTemperatureMin = r->ReadShort("m_idealTemperatureMin");
            entry.m_idealTemperatureMax = r->ReadShort("m_idealTemperatureMax");
            entry.m_isBlocking = r->ReadBool("m_isBlocking");
            entry.m_useBigChallengeAps = r->ReadBool("m_useBigChallengeAps");
            entry.m_isMonsterEmbryo = r->ReadBool("m_isMonsterEmbryo");
            entry.m_monsterStepHatching = r->ReadShort("m_monsterStepHatching");
            entry.m_properties = r->ReadIntArray("m_properties");
            entry.m_monsterFamilies = r->ReadIntArray("m_monsterFamilies");

            qint32 stepCount = r->ReadInt();

            for (qint32 i = 0; i < stepCount; ++i)
            {
                ResourceStep resourceStep;

                resourceStep.m_index = r->ReadInt();
                qint32 actionCount = r->ReadInt();

                for (qint32 j = 0; j < actionCount; ++j)
                {
                    ResourceStepAction resourceStepAction;

                    resourceStepAction.m_id = r->ReadInt();
                    resourceStepAction.m_skillId = r->ReadInt();
                    resourceStepAction.m_resourceNextIndex = r->ReadInt();
                    resourceStepAction.m_skillLevelRequired = r->ReadInt();
                    resourceStepAction.m_skillSimultaneousPlayer = r->ReadInt();
                    resourceStepAction.m_skillVisualFeedbackId = r->ReadInt();
                    resourceStepAction.m_duration = r->ReadInt();
                    resourceStepAction.m_consumableId = r->ReadInt();
                    resourceStepAction.m_gfxId = r->ReadInt();
                    resourceStepAction.m_criteria = r->ReadString();
                    resourceStepAction.m_collectLootListId = r->ReadInt();
                    resourceStepAction.m_collectItemId = r->ReadInt();
                    resourceStepAction.m_lootItems = r->ReadIntArray();
                    resourceStepAction.m_mruOrder = r->ReadInt();
                    resourceStepAction.m_displayInCraftDialog = r->ReadBool();

                    resourceStep.m_actions.push_back(resourceStepAction);
                }
                resourceStep.m_sizeCategoryId = r->ReadInt();
                resourceStep.m_lightRadius = r->ReadInt();
                resourceStep.m_lightColor = r->ReadInt();
                resourceStep.m_apsId = r->ReadInt();
                resourceStep.m_apsPosZ = r->ReadInt();

                entry.m_steps.push_back(resourceStep);
            }

            entry.m_height = r->ReadShort("m_height");
            entry.m_iconGfxId = r->ReadInt("m_iconGfxId");

            qint32 gfxIdCount = r->ReadInt();

            for (qint32 i = 0; i < gfxIdCount; ++i)
            {
                qint32 gfxIdKey = r->ReadInt();
                QList<qint32> gfxIdValue = r->ReadIntArray();

                entry.m_gfxIds.insert(gfxIdKey, gfxIdValue);
            }

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};
