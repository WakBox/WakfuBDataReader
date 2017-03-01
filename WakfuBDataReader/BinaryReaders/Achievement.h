#include "BaseBinaryReader.h"

struct AchievementEntry
{
    struct AchievementGoal;
    struct AchievementReward;

    qint32 m_id;
    qint32 m_categoryId;
    bool m_isVisible;
    bool m_notifyOnPass;
    bool m_isActive;
    QString m_criterion;
    QString m_activationCriterion;
    QList<AchievementGoal> m_goals;
    QList<AchievementReward> m_rewards;
    qint32 m_duration;
    qint32 m_cooldown;
    bool m_shareable;
    bool m_repeatable;
    bool m_needsUserAccept;
    qint32 m_recommandedLevel;
    qint32 m_recommandedPlayers;
    bool m_followable;
    qint32 m_displayOnActivationDelay;
    qint64 m_periodStartTime;
    qint64 m_period;
    bool m_autoCompass;
    qint32 m_gfxId;
    bool m_isMercenary;
    qint32 m_mercenaryItemId;
    qint8 m_mercenaryRank;
    qint32 m_order;

    struct AchievementGoal
    {
        struct AchievementVariableListener;

        qint32 m_id;
        bool m_feedback;
        bool m_hasPositionFeedback;
        qint16 m_positionX;
        qint16 m_positionY;
        qint16 m_positionZ;
        qint16 m_positionWorldId;
        QList<AchievementVariableListener> m_vlisteners;

        struct AchievementVariableListener
        {
            qint32 m_id;
            QString m_successCriterion;
            QList<qint32> m_variableIds;
        };
    };

    struct AchievementReward
    {
        qint32 m_id;
        qint32 m_type;
        QList<qint32> m_params;
    };
};

class Achievement : public BaseBinaryReader
{
public:
    Achievement() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            AchievementEntry entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_categoryId = r->ReadInt("m_categoryId");
            entry.m_isVisible = r->ReadBool("m_isVisible");
            entry.m_notifyOnPass = r->ReadBool("m_notifyOnPass");
            entry.m_isActive = r->ReadBool("m_isActive");
            entry.m_criterion = r->ReadString("m_criterion");
            entry.m_activationCriterion = r->ReadString("m_activationCriterion");

            qint32 achievementGoalSize = r->ReadInt();

            for (qint32 i = 0; i < achievementGoalSize; ++i)
            {
                AchievementEntry::AchievementGoal achievementGoal;

                achievementGoal.m_id = r->ReadInt();
                achievementGoal.m_feedback = r->ReadBool();
                achievementGoal.m_hasPositionFeedback = r->ReadBool();
                achievementGoal.m_positionX = r->ReadShort();
                achievementGoal.m_positionY = r->ReadShort();
                achievementGoal.m_positionZ = r->ReadShort();
                achievementGoal.m_positionWorldId = r->ReadShort();

                qint32 achievementVariableListenerSize = r->ReadInt();

                for (qint32 j = 0; j < achievementVariableListenerSize; ++j)
                {
                    AchievementEntry::AchievementGoal::AchievementVariableListener achievementVariableListener;

                    achievementVariableListener.m_id = r->ReadInt();
                    achievementVariableListener.m_successCriterion = r->ReadString();
                    achievementVariableListener.m_variableIds = r->ReadIntArray();

                    achievementGoal.m_vlisteners.push_back(achievementVariableListener);
                }

                entry.m_goals.push_back(achievementGoal);
            }

            qint32 achievementRewardSize = r->ReadInt();

            for (qint32 i = 0; i < achievementRewardSize; ++i)
            {
                AchievementEntry::AchievementReward achievementReward;

                achievementReward.m_id = r->ReadInt();
                achievementReward.m_type = r->ReadInt();
                achievementReward.m_params = r->ReadIntArray();

                entry.m_rewards.push_back(achievementReward);
            }

            entry.m_duration = r->ReadInt("m_duration");
            entry.m_cooldown = r->ReadInt("m_cooldown");
            entry.m_shareable = r->ReadBool("m_shareable");
            entry.m_repeatable = r->ReadBool("m_repeatable");
            entry.m_needsUserAccept = r->ReadBool("m_needsUserAccept");
            entry.m_recommandedLevel = r->ReadInt("m_recommandedLevel");
            entry.m_recommandedPlayers = r->ReadInt("m_recommandedPlayers");
            entry.m_followable = r->ReadBool("m_followable");
            entry.m_displayOnActivationDelay = r->ReadInt("m_displayOnActivationDelay");
            entry.m_periodStartTime = r->ReadLong("m_periodStartTime");
            entry.m_period = r->ReadLong("m_period");
            entry.m_autoCompass = r->ReadBool("m_autoCompass");
            entry.m_gfxId = r->ReadInt("m_gfxId");
            entry.m_isMercenary = r->ReadBool("m_isMercenary");
            entry.m_mercenaryItemId = r->ReadInt("m_mercenaryItemId");
            entry.m_mercenaryRank = r->ReadByte("m_mercenaryRank");
            entry.m_order = r->ReadInt("m_order");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};
