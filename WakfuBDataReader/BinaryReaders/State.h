#ifndef STATE_H
#define STATE_H

#include "BaseBinaryReader.h"

struct StateBinaryData
{
    qint32 m_id;
    qint16 m_maxLevel;
    QList<qint32> m_endTrigger;
    QList<qint32> m_duration;
    QList<float> m_durationInc;
    bool m_endsAtEndOfTurn;
    bool m_isDurationInFullTurns;
    bool m_inTurnInFight;
    bool m_isReplacable;
    bool m_isTransmigrable;
    QString m_hmiActions;
    QString m_applyCriterion;
    bool m_isCumulable;
    bool m_durationInCasterTurn;
    bool m_durationInRealTime;
    QList<qint32> m_effectIds;
    QList<qint32> m_stateImmunities;
    bool m_stateShouldBeSaved;
    bool m_decursable;
    qint8 m_stateType;
    qint8 m_statePowerType;
    bool m_isReapplyEvenAtMaxLevel;
    bool m_timelineVisible;
    qint32 m_gfxId;
    bool m_displayCasterName;
};

class State : public BaseBinaryReader
{
public:
    State() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            StateBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_maxLevel = r->ReadShort("m_maxLevel");
            entry.m_endTrigger = r->ReadIntArray("m_endTrigger");
            entry.m_duration = r->ReadIntArray("m_duration");
            entry.m_durationInc = r->ReadFloatArray("m_durationInc");
            entry.m_endsAtEndOfTurn = r->ReadBool("m_endsAtEndOfTurn");
            entry.m_isDurationInFullTurns = r->ReadBool("m_isDurationInFullTurns");
            entry.m_inTurnInFight = r->ReadBool("m_inTurnInFight");
            entry.m_isReplacable = r->ReadBool("m_isReplacable");
            entry.m_isTransmigrable = r->ReadBool("m_isTransmigrable");
            entry.m_hmiActions = r->ReadString("m_hmiActions");
            entry.m_applyCriterion = r->ReadString("m_applyCriterion");
            entry.m_isCumulable = r->ReadBool("m_isCumulable");
            entry.m_durationInCasterTurn = r->ReadBool("m_durationInCasterTurn");
            entry.m_durationInRealTime = r->ReadBool("m_durationInRealTime");
            entry.m_effectIds = r->ReadIntArray("m_effectIds");
            entry.m_stateImmunities = r->ReadIntArray("m_stateImmunities");
            entry.m_stateShouldBeSaved = r->ReadBool("m_stateShouldBeSaved");
            entry.m_decursable = r->ReadBool("m_decursable");
            entry.m_stateType = r->ReadByte("m_stateType");
            entry.m_statePowerType = r->ReadByte("m_statePowerType");
            entry.m_isReapplyEvenAtMaxLevel = r->ReadBool("m_isReapplyEvenAtMaxLevel");
            entry.m_timelineVisible = r->ReadBool("m_timelineVisible");
            entry.m_gfxId = r->ReadInt("m_gfxId");
            entry.m_displayCasterName = r->ReadBool("m_displayCasterName");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif