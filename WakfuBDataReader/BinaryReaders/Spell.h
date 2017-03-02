#include "BaseBinaryReader.h"

struct CustomCharac
{
    qint32 m_base;
    float m_increment;
};

struct CastParam
{
    QList<TByteObjectHashMap<CustomCharac>(costCount);> m_costs;
    QList<CustomCharac();> final CustomCharac costValue;
    qint32 m_cost;
    float m_PA_base;
    float m_PA_inc;
    float m_PM_base;
    float m_PM_inc;
    float m_PW_base;
    float m_PW_inc;
    float m_rangeMinBase;
    float m_rangeMinInc;
    float m_rangeMaxBase;
    float m_rangeMaxInc;
    bool m_isLosAware;
    bool m_onlyInLine;
    bool m_rangeIsDynamic;
};

struct SpellBinaryData
{
    qint32 m_id;
    qint32 m_scriptId;
    qint32 m_gfxId;
    qint16 m_maxLevel;
    qint16 m_breedId;
    qint16 m_castMaxPerTarget;
    float m_castMaxPerTurn;
    float m_castMaxPerTurnIncr;
    qint16 m_castMinInterval;
    bool m_testLineOfSight;
    bool m_castOnlyLine;
    bool m_castOnlyInDiag;
    bool m_testFreeCell;
    bool m_testNotBorderCell;
    bool m_testDirectPath;
    qint32 m_targetFilter;
    QString m_castCriterion;
    float m_PA_base;
    float m_PA_inc;
    float m_PM_base;
    float m_PM_inc;
    float m_PW_base;
    float m_PW_inc;
    float m_rangeMaxBase;
    float m_rangeMaxInc;
    float m_rangeMinBase;
    float m_rangeMinLevelIncrement;
    qint16 m_maxEffectCap;
    qint16 m_element;
    qint16 m_xpGainPercentage;
    qint16 m_spellType;
    qint16 m_uiPosition;
    QString m_learnCriteria;
    qint8 m_passive;
    bool m_useAutomaticDescription;
    bool m_showInTimeline;
    bool m_canCastWhenCarrying;
    qint8 m_actionOnCriticalMiss;
    bool m_spellCastRangeIsDynamic;
    bool m_castSpellWillBreakInvisibility;
    bool m_castOnRandomCell;
    bool m_tunnelable;
    bool m_canCastOnCasterCell;
    bool m_associatedWithItemUse;
    QList<qint32> m_properties;
    QList<qint32> m_effectIds;
    QList<TByteObjectHashMap<CustomCharac>(baseCastParameterCount);> m_baseCastParameters;
    QList<CustomCharac();> final CustomCharac baseCastParameterValue;
    QList<THashMap<String, CastParam>(alternativeCastCount);> m_alternativeCasts;
    QList<CastParam();> final CastParam alternativeCastValue;
};

class Spell : public BaseBinaryReader
{
public:
    Spell() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            SpellBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_scriptId = r->ReadInt("m_scriptId");
            entry.m_gfxId = r->ReadInt("m_gfxId");
            entry.m_maxLevel = r->ReadShort("m_maxLevel");
            entry.m_breedId = r->ReadShort("m_breedId");
            entry.m_castMaxPerTarget = r->ReadShort("m_castMaxPerTarget");
            entry.m_castMaxPerTurn = r->ReadFloat("m_castMaxPerTurn");
            entry.m_castMaxPerTurnIncr = r->ReadFloat("m_castMaxPerTurnIncr");
            entry.m_castMinInterval = r->ReadShort("m_castMinInterval");
            entry.m_testLineOfSight = r->ReadBool("m_testLineOfSight");
            entry.m_castOnlyLine = r->ReadBool("m_castOnlyLine");
            entry.m_castOnlyInDiag = r->ReadBool("m_castOnlyInDiag");
            entry.m_testFreeCell = r->ReadBool("m_testFreeCell");
            entry.m_testNotBorderCell = r->ReadBool("m_testNotBorderCell");
            entry.m_testDirectPath = r->ReadBool("m_testDirectPath");
            entry.m_targetFilter = r->ReadInt("m_targetFilter");
            entry.m_castCriterion = r->ReadString("m_castCriterion");
            entry.m_PA_base = r->ReadFloat("m_PA_base");
            entry.m_PA_inc = r->ReadFloat("m_PA_inc");
            entry.m_PM_base = r->ReadFloat("m_PM_base");
            entry.m_PM_inc = r->ReadFloat("m_PM_inc");
            entry.m_PW_base = r->ReadFloat("m_PW_base");
            entry.m_PW_inc = r->ReadFloat("m_PW_inc");
            entry.m_rangeMaxBase = r->ReadFloat("m_rangeMaxBase");
            entry.m_rangeMaxInc = r->ReadFloat("m_rangeMaxInc");
            entry.m_rangeMinBase = r->ReadFloat("m_rangeMinBase");
            entry.m_rangeMinLevelIncrement = r->ReadFloat("m_rangeMinLevelIncrement");
            entry.m_maxEffectCap = r->ReadShort("m_maxEffectCap");
            entry.m_element = r->ReadShort("m_element");
            entry.m_xpGainPercentage = r->ReadShort("m_xpGainPercentage");
            entry.m_spellType = r->ReadShort("m_spellType");
            entry.m_uiPosition = r->ReadShort("m_uiPosition");
            entry.m_learnCriteria = r->ReadString("m_learnCriteria");
            entry.m_passive = r->ReadByte("m_passive");
            entry.m_useAutomaticDescription = r->ReadBool("m_useAutomaticDescription");
            entry.m_showInTimeline = r->ReadBool("m_showInTimeline");
            entry.m_canCastWhenCarrying = r->ReadBool("m_canCastWhenCarrying");
            entry.m_actionOnCriticalMiss = r->ReadByte("m_actionOnCriticalMiss");
            entry.m_spellCastRangeIsDynamic = r->ReadBool("m_spellCastRangeIsDynamic");
            entry.m_castSpellWillBreakInvisibility = r->ReadBool("m_castSpellWillBreakInvisibility");
            entry.m_castOnRandomCell = r->ReadBool("m_castOnRandomCell");
            entry.m_tunnelable = r->ReadBool("m_tunnelable");
            entry.m_canCastOnCasterCell = r->ReadBool("m_canCastOnCasterCell");
            entry.m_associatedWithItemUse = r->ReadBool("m_associatedWithItemUse");
            entry.m_properties = r->ReadIntArray("m_properties");
            entry.m_effectIds = r->ReadIntArray("m_effectIds");

            qint32 baseCastParameterCount = r->ReadInt();

            for (qint32 i = 0; i < baseCastParameterCount; ++i)
            {
                TByteObjectHashMap<CustomCharac>(baseCastParameterCount); tByteObjectHashMap<CustomCharac>(baseCastParameterCount);;


                entry.m_baseCastParameters.push_back(tByteObjectHashMap<CustomCharac>(baseCastParameterCount););
            }


            qint32 baseCastParameterKey = r->ReadByte();

            for (qint32 i = 0; i < baseCastParameterKey; ++i)
            {
                CustomCharac(); customCharac();;


                entry.final CustomCharac baseCastParameterValue.push_back(customCharac(););
            }


            qint32 alternativeCastCount = r->ReadInt();

            for (qint32 i = 0; i < alternativeCastCount; ++i)
            {
                THashMap<String, CastParam>(alternativeCastCount); tHashMap<String, CastParam>(alternativeCastCount);;


                entry.m_alternativeCasts.push_back(tHashMap<String, CastParam>(alternativeCastCount););
            }


            qint32 alternativeCastKey = r->ReadString();

            for (qint32 i = 0; i < alternativeCastKey; ++i)
            {
                CastParam(); castParam();;


                entry.final CastParam alternativeCastValue.push_back(castParam(););
            }


            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};