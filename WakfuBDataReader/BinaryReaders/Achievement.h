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

            /* Struct
            r->ReadInt("id");
            r->ReadInt("categoryId");
            r->ReadBool("isVisible");
            r->ReadBool("notifyOnPass");
            r->ReadBool("IsActive");
            r->ReadString("m_criterion");
            //r->ReadString("m_activationCriterion");

            // AchievementGoal
            qint32 size = r->ReadInt(QString());
            for (quint32 i = 0; i < size; ++i)
            {
                r->ReadInt("m_id");
                r->ReadBool("m_feedback");
                r->ReadBool("m_hasPositionFeedback");
                r->ReadShort("m_positionX");
                r->ReadShort("m_positionY");
                r->ReadShort("m_positionZ");
                r->ReadShort("m_positionWorldId");

                // AchievementVariableListener
                qint32 size2 = r->ReadInt(QString());
                for (quint32 j = 0; j < size2; ++j)
                {
                    r->ReadInt("m_id");
                    r->ReadString("m_successCriterion");
                    r->ReadIntArray("m_variableIds");
                }
            }

            // AchievementReward
            size = r->ReadInt(QString());
            for (quint32 i = 0; i < size; ++i)
            {
                r->ReadInt("m_id");
                r->ReadInt("m_type");
                r->ReadIntArray("m_params");
            }

            r->ReadInt("Duration");
            r->ReadInt("m_cooldown");
            r->ReadBool("m_shareable");
            r->ReadBool("m_repeatable");
            r->ReadBool("m_needsUserAccept");
            r->ReadInt("m_recommandedLevel");
            r->ReadInt("m_recommandedPlayers");
            r->ReadBool("m_followable");
            r->ReadInt("m_displayOnActivationDelay");
            r->ReadLong("m_periodStartTime");
            r->ReadLong("m_period");
            r->ReadBool("m_autoCompass");
            r->ReadInt("m_gfxId");
            r->ReadBool("m_isMercenary");
            r->ReadInt("m_mercenaryItemId");
            r->ReadByte("m_mercenaryRank");
            r->ReadInt("m_order");
            */
            r->PushRow();

            break;
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};
