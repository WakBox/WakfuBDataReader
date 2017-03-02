#include "BaseBinaryReader.h"

struct Reward
{
    qint32 m_id;
    QString m_criterion;
    qint16 m_xpLevel;
    qint16 m_dropLevel;
};

struct FightChallengeBinaryData
{
    qint32 m_id;
    qint32 m_dropWeight;
    QString m_dropCriterion;
    qint32 m_stateId;
    qint32 m_listenedEffectSuccess;
    qint32 m_listenedEffectFailure;
    qint32 m_gfxId;
    bool m_isBase;
    QList<qint32> m_incompatibleChallenges;
    QList<qint32> m_incompatibleMonsters;
    QList<Reward> m_rewards;
};

class FightChallenge : public BaseBinaryReader
{
public:
    FightChallenge() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            FightChallengeBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_dropWeight = r->ReadInt("m_dropWeight");
            entry.m_dropCriterion = r->ReadString("m_dropCriterion");
            entry.m_stateId = r->ReadInt("m_stateId");
            entry.m_listenedEffectSuccess = r->ReadInt("m_listenedEffectSuccess");
            entry.m_listenedEffectFailure = r->ReadInt("m_listenedEffectFailure");
            entry.m_gfxId = r->ReadInt("m_gfxId");
            entry.m_isBase = r->ReadBool("m_isBase");
            entry.m_incompatibleChallenges = r->ReadIntArray("m_incompatibleChallenges");
            entry.m_incompatibleMonsters = r->ReadIntArray("m_incompatibleMonsters");

            qint32 rewardCount = r->ReadInt();

            for (qint32 i = 0; i < rewardCount; ++i)
            {
                Reward reward;

                reward.m_id = r->ReadInt();
                reward.m_criterion = r->ReadString();
                reward.m_xpLevel = r->ReadShort();
                reward.m_dropLevel = r->ReadShort();

                entry.m_rewards.push_back(reward);
            }


            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};