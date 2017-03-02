#include "BaseBinaryReader.h"

struct RankDef
{
    qint32 m_levelOrder;
    qint32 m_scoreMinD;
    qint32 m_scoreMinC;
    qint32 m_scoreMinB;
    qint32 m_scoreMinA;
};

struct Reward
{
    qint32 m_scoreMin;
    qint32 m_itemId;
    qint32 m_xpValue;
    qint8 m_rankNeeded;
};

struct RewardList
{
    qint32 m_id;
    qint32 m_levelOrder;
    QList<Reward> m_rewards;
};

struct Challenge
{
    qint32 m_id;
    float m_ratio;
};

struct ArcadeDungeonBinaryData
{
    qint32 m_id;
    qint16 m_worldId;
    QList<Challenge> m_challenges;
    QList<RewardList> m_rewardsList;
    QList<RankDef> m_ranks;
    qint32 m_scoreRoundBase;
    qint32 m_scoreRoundIncr;
};

class ArcadeDungeon : public BaseBinaryReader
{
public:
    ArcadeDungeon() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            ArcadeDungeonBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_worldId = r->ReadShort("m_worldId");

            qint32 challengeCount = r->ReadInt();

            for (qint32 i = 0; i < challengeCount; ++i)
            {
                Challenge challenge;

                challenge.m_id = r->ReadInt();
                challenge.m_ratio = r->ReadFloat();

                entry.m_challenges.push_back(challenge);
            }


            qint32 rewardsListCount = r->ReadInt();

            for (qint32 i = 0; i < rewardsListCount; ++i)
            {
                RewardList rewardList;

                rewardList.m_id = r->ReadInt();
                rewardList.m_levelOrder = r->ReadInt();
                qint32 rewardCount = r->ReadInt();

                for (qint32 j = 0; j < rewardCount; ++j)
                {
                    Reward reward;

                    reward.m_scoreMin = r->ReadInt();
                    reward.m_itemId = r->ReadInt();
                    reward.m_xpValue = r->ReadInt();
                    reward.m_rankNeeded = r->ReadByte();

                    rewardList.m_rewards.push_back(reward);
                }

                entry.m_rewardsList.push_back(rewardList);
            }


            qint32 rankCount = r->ReadInt();

            for (qint32 i = 0; i < rankCount; ++i)
            {
                RankDef rankDef;

                rankDef.m_levelOrder = r->ReadInt();
                rankDef.m_scoreMinD = r->ReadInt();
                rankDef.m_scoreMinC = r->ReadInt();
                rankDef.m_scoreMinB = r->ReadInt();
                rankDef.m_scoreMinA = r->ReadInt();

                entry.m_ranks.push_back(rankDef);
            }

            entry.m_scoreRoundBase = r->ReadInt("m_scoreRoundBase");
            entry.m_scoreRoundIncr = r->ReadInt("m_scoreRoundIncr");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};