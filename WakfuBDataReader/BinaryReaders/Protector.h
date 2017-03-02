#include "BaseBinaryReader.h"

struct ProtectorFaunaWill
{
    qint32 m_typeId;
    qint16 m_min;
    qint16 m_max;
};

struct ProtectorFloraWill
{
    qint32 m_typeId;
    qint16 m_min;
    qint16 m_max;
};

struct ProtectorSecret
{
    qint32 m_id;
    qint32 m_achievementGoalId;
    qint32 m_secretGfxId;
    qint32 m_discoveredGfxId;
};

struct ProtectorBinaryData
{
    qint32 m_protectorId;
    qint32 m_monsterId;
    qint32 m_buffListId;
    qint32 m_buffListIdToBuy;
    qint32 m_scenarioLootListId;
    qint32 m_scenarioLootListIdToBuy;
    qint32 m_scenarioLootListIdChaos;
    qint32 m_scenarioLootListIdEcosystem;
    qint32 m_climateListIdToBuy;
    qint32 m_nationId;
    qint32 m_territory;
    qint32 m_fightStake;
    qint32 m_positionX;
    qint32 m_positionY;
    qint16 m_positionZ;
    QList<qint32> m_craftLearnt;
    QList<ProtectorSecret> m_secrets;
    QList<ProtectorFaunaWill> m_faunaWill;
    QList<ProtectorFloraWill> m_floraWill;
};

class Protector : public BaseBinaryReader
{
public:
    Protector() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            ProtectorBinaryData entry;

            entry.m_protectorId = r->ReadInt("m_protectorId");
            entry.m_monsterId = r->ReadInt("m_monsterId");
            entry.m_buffListId = r->ReadInt("m_buffListId");
            entry.m_buffListIdToBuy = r->ReadInt("m_buffListIdToBuy");
            entry.m_scenarioLootListId = r->ReadInt("m_scenarioLootListId");
            entry.m_scenarioLootListIdToBuy = r->ReadInt("m_scenarioLootListIdToBuy");
            entry.m_scenarioLootListIdChaos = r->ReadInt("m_scenarioLootListIdChaos");
            entry.m_scenarioLootListIdEcosystem = r->ReadInt("m_scenarioLootListIdEcosystem");
            entry.m_climateListIdToBuy = r->ReadInt("m_climateListIdToBuy");
            entry.m_nationId = r->ReadInt("m_nationId");
            entry.m_territory = r->ReadInt("m_territory");
            entry.m_fightStake = r->ReadInt("m_fightStake");
            entry.m_positionX = r->ReadInt("m_positionX");
            entry.m_positionY = r->ReadInt("m_positionY");
            entry.m_positionZ = r->ReadShort("m_positionZ");
            entry.m_craftLearnt = r->ReadIntArray("m_craftLearnt");

            qint32 secretCount = r->ReadInt();

            for (qint32 i = 0; i < secretCount; ++i)
            {
                ProtectorSecret protectorSecret;

                protectorSecret.m_id = r->ReadInt();
                protectorSecret.m_achievementGoalId = r->ReadInt();
                protectorSecret.m_secretGfxId = r->ReadInt();
                protectorSecret.m_discoveredGfxId = r->ReadInt();

                entry.m_secrets.push_back(protectorSecret);
            }


            qint32 faunaWillCount = r->ReadInt();

            for (qint32 i = 0; i < faunaWillCount; ++i)
            {
                ProtectorFaunaWill protectorFaunaWill;

                protectorFaunaWill.m_typeId = r->ReadInt();
                protectorFaunaWill.m_min = r->ReadShort();
                protectorFaunaWill.m_max = r->ReadShort();

                entry.m_faunaWill.push_back(protectorFaunaWill);
            }


            qint32 floraWillCount = r->ReadInt();

            for (qint32 i = 0; i < floraWillCount; ++i)
            {
                ProtectorFloraWill protectorFloraWill;

                protectorFloraWill.m_typeId = r->ReadInt();
                protectorFloraWill.m_min = r->ReadShort();
                protectorFloraWill.m_max = r->ReadShort();

                entry.m_floraWill.push_back(protectorFloraWill);
            }


            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};