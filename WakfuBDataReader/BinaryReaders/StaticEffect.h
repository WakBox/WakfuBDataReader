#ifndef STATICEFFECT_H
#define STATICEFFECT_H

#include "BaseBinaryReader.h"

struct StaticEffectBinaryData
{
    qint32 m_effectId;
    qint32 m_actionId;
    qint32 m_parentId;
    qint16 m_areaOrderingMethod;
    QList<qint32> m_areaSize;
    qint16 m_areaShape;
    qint16 m_emptyCellsAreaOrderingMethod;
    QList<qint32> m_emptyCellsAreaSize;
    qint16 m_emptyCellsAreaShape;
    QList<qint32> m_triggersBeforeComputation;
    QList<qint32> m_triggersBeforeExecution;
    QList<qint32> m_triggersForUnapplication;
    QList<qint32> m_triggersAfterExecution;
    QList<qint32> m_triggersAfterAllExecutions;
    QList<qint32> m_triggersNotRelatedToExecutions;
    QList<qint32> m_triggersAdditionnal;
    QString m_criticalState;
    QList<qint64> m_targetValidator;
    bool m_affectedByLocalisation;
    qint32 m_durationBase;
    float m_durationInc;
    bool m_endsAtEndOfTurn;
    bool m_isDurationInFullTurns;
    qint16 m_applyDelayBase;
    float m_applyDelayIncrement;
    QList<float> m_params;
    float m_probabilityBase;
    float m_probabilityInc;
    qint8 m_triggerListenerType;
    qint8 m_triggerTargetType;
    qint8 m_triggerCasterType;
    bool m_storeOnSelf;
    qint16 m_maxExecution;
    float m_maxExecutionIncr;
    qint8 m_maxTargetCount;
    bool m_isFightEffect;
    QString m_hmiAction;
    qint16 m_containerMinLevel;
    qint16 m_containerMaxLevel;
    QString m_effectCriterion;
    QString m_effectParentType;
    QString m_effectContainerType;
    bool m_dontTriggerAnything;
    bool m_isPersonal;
    bool m_isDecursable;
    bool m_notifyInChatForCaster;
    bool m_notifyInChatForTarget;
    bool m_notifyInChatWithCasterName;
    qint32 m_scriptFileId;
    bool m_durationInCasterTurn;
    QList<qint32> m_effectProperties;
    bool m_displayInSpellDescription;
    bool m_displayInStateBar;
    bool m_recomputeAreaOfEffectDisplay;
    bool m_isInTurnInFight;
    bool m_notifyInChat;
};

class StaticEffect : public BaseBinaryReader
{
public:
    StaticEffect() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            StaticEffectBinaryData entry;

            entry.m_effectId = r->ReadInt("m_effectId");
            entry.m_actionId = r->ReadInt("m_actionId");
            entry.m_parentId = r->ReadInt("m_parentId");
            entry.m_areaOrderingMethod = r->ReadShort("m_areaOrderingMethod");
            entry.m_areaSize = r->ReadIntArray("m_areaSize");
            entry.m_areaShape = r->ReadShort("m_areaShape");
            entry.m_emptyCellsAreaOrderingMethod = r->ReadShort("m_emptyCellsAreaOrderingMethod");
            entry.m_emptyCellsAreaSize = r->ReadIntArray("m_emptyCellsAreaSize");
            entry.m_emptyCellsAreaShape = r->ReadShort("m_emptyCellsAreaShape");
            entry.m_triggersBeforeComputation = r->ReadIntArray("m_triggersBeforeComputation");
            entry.m_triggersBeforeExecution = r->ReadIntArray("m_triggersBeforeExecution");
            entry.m_triggersForUnapplication = r->ReadIntArray("m_triggersForUnapplication");
            entry.m_triggersAfterExecution = r->ReadIntArray("m_triggersAfterExecution");
            entry.m_triggersAfterAllExecutions = r->ReadIntArray("m_triggersAfterAllExecutions");
            entry.m_triggersNotRelatedToExecutions = r->ReadIntArray("m_triggersNotRelatedToExecutions");
            entry.m_triggersAdditionnal = r->ReadIntArray("m_triggersAdditionnal");
            entry.m_criticalState = r->ReadString("m_criticalState");
            entry.m_targetValidator = r->ReadLongArray("m_targetValidator");
            entry.m_affectedByLocalisation = r->ReadBool("m_affectedByLocalisation");
            entry.m_durationBase = r->ReadInt("m_durationBase");
            entry.m_durationInc = r->ReadFloat("m_durationInc");
            entry.m_endsAtEndOfTurn = r->ReadBool("m_endsAtEndOfTurn");
            entry.m_isDurationInFullTurns = r->ReadBool("m_isDurationInFullTurns");
            entry.m_applyDelayBase = r->ReadShort("m_applyDelayBase");
            entry.m_applyDelayIncrement = r->ReadFloat("m_applyDelayIncrement");
            entry.m_params = r->ReadFloatArray("m_params");
            entry.m_probabilityBase = r->ReadFloat("m_probabilityBase");
            entry.m_probabilityInc = r->ReadFloat("m_probabilityInc");
            entry.m_triggerListenerType = r->ReadByte("m_triggerListenerType");
            entry.m_triggerTargetType = r->ReadByte("m_triggerTargetType");
            entry.m_triggerCasterType = r->ReadByte("m_triggerCasterType");
            entry.m_storeOnSelf = r->ReadBool("m_storeOnSelf");
            entry.m_maxExecution = r->ReadShort("m_maxExecution");
            entry.m_maxExecutionIncr = r->ReadFloat("m_maxExecutionIncr");
            entry.m_maxTargetCount = r->ReadByte("m_maxTargetCount");
            entry.m_isFightEffect = r->ReadBool("m_isFightEffect");
            entry.m_hmiAction = r->ReadString("m_hmiAction");
            entry.m_containerMinLevel = r->ReadShort("m_containerMinLevel");
            entry.m_containerMaxLevel = r->ReadShort("m_containerMaxLevel");
            entry.m_effectCriterion = r->ReadString("m_effectCriterion");
            entry.m_effectParentType = r->ReadString("m_effectParentType");
            entry.m_effectContainerType = r->ReadString("m_effectContainerType");
            entry.m_dontTriggerAnything = r->ReadBool("m_dontTriggerAnything");
            entry.m_isPersonal = r->ReadBool("m_isPersonal");
            entry.m_isDecursable = r->ReadBool("m_isDecursable");
            entry.m_notifyInChatForCaster = r->ReadBool("m_notifyInChatForCaster");
            entry.m_notifyInChatForTarget = r->ReadBool("m_notifyInChatForTarget");
            entry.m_notifyInChatWithCasterName = r->ReadBool("m_notifyInChatWithCasterName");
            entry.m_scriptFileId = r->ReadInt("m_scriptFileId");
            entry.m_durationInCasterTurn = r->ReadBool("m_durationInCasterTurn");
            entry.m_effectProperties = r->ReadIntArray("m_effectProperties");
            entry.m_displayInSpellDescription = r->ReadBool("m_displayInSpellDescription");
            entry.m_displayInStateBar = r->ReadBool("m_displayInStateBar");
            entry.m_recomputeAreaOfEffectDisplay = r->ReadBool("m_recomputeAreaOfEffectDisplay");
            entry.m_isInTurnInFight = r->ReadBool("m_isInTurnInFight");
            entry.m_notifyInChat = r->ReadBool("m_notifyInChat");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif