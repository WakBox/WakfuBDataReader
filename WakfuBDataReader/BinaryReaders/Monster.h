#ifndef MONSTER_H
#define MONSTER_H

#include "BaseBinaryReader.h"

struct SpellInfo
{
    qint32 m_id;
    qint32 m_level;
};

struct Equipement
{
    QString m_fileId;
    QList<QString> m_parts;
};

struct MonsterColor
{
    qint32 m_partIndex;
    qint32 m_color;
};

struct Anim
{
    qint8 m_key;
    QString m_animName;
};

struct MonsterCollectActionData
{
    qint32 m_id;
    qint32 m_skillId;
    qint32 m_skillLevelRequired;
    qint32 m_skillVisualFeedbackId;
    QString m_criteria;
    float m_xpFactor;
    qint32 m_collectLootListId;
    qint32 m_duration;
    qint32 m_collectItemId;
    QList<qint32> m_lootList;
    bool m_displayInCraftDialog;
};

struct MonsterAction
{
    qint32 m_id;
    qint8 m_type;
    QString m_criteria;
    bool m_criteriaOnNpc;
    bool m_moveToMonsterBeforeInteractWithHim;
    qint32 m_duration;
    bool m_showProgressBar;
    qint32 m_visualId;
    qint32 m_scriptId;
};

struct MonsterBehaviourData
{
    qint32 m_id;
    qint32 m_type;
    qint32 m_scriptId;
    bool m_needsToWaitPathEnd;
};

struct MonsterEvolutionData
{
    qint32 m_id;
    qint32 m_breedId;
    qint32 m_scriptId;
};

struct MonsterBinaryData
{
    qint32 m_id;
    qint32 m_familyId;
    qint16 m_levelMin;
    qint16 m_levelMax;
    float m_xpMultiplicator;
    float m_arcadePointsMultiplicator;
    qint32 m_baseHp;
    qint32 m_baseWp;
    qint32 m_baseAp;
    qint32 m_baseMp;
    qint32 m_baseRange;
    qint32 m_baseInit;
    qint32 m_basePerception;
    qint32 m_baseParade;
    qint32 m_baseWill;
    qint32 m_baseCriticalHit;
    qint32 m_baseTimeBeforeDeath;
    float m_HpInc;
    float m_WpInc;
    float m_ApInc;
    float m_MpInc;
    float m_rangeInc;
    float m_initInc;
    float m_perceptionInc;
    float m_paradeInc;
    float m_willInc;
    float m_CriticalHitInc;
    qint32 m_baseHealingBonus;
    qint32 m_baseSummonBonus;
    qint32 m_baseMechanicsBonus;
    qint32 m_baseTackleBonus;
    qint32 m_baseFireDamageBonus;
    qint32 m_baseWaterDamageBonus;
    qint32 m_baseEarthDamageBonus;
    qint32 m_baseWindDamageBonus;
    qint32 m_baseFireResistance;
    qint32 m_baseWaterResistance;
    qint32 m_baseEarthResistance;
    qint32 m_baseWindResistance;
    qint32 m_baseTackleResistance;
    qint32 m_baseAPLossResistance;
    qint32 m_basePMLossResistance;
    qint32 m_baseWPLossResistance;
    float m_healingBonusInc;
    float m_tackleBonusInc;
    float m_fireDamageBonusInc;
    float m_waterDamageBonusInc;
    float m_earthDamageBonusInc;
    float m_windDamageBonusInc;
    float m_fireResistanceInc;
    float m_waterResistanceInc;
    float m_earthResistanceInc;
    float m_windResistanceInc;
    float m_tackleResistanceInc;
    float m_apLossResistanceInc;
    float m_pmLossResistanceInc;
    float m_wpLossResistanceInc;
    bool m_hasDeadEvolution;
    qint16 m_npcRank;
    qint16 m_agroRadius;
    qint16 m_sightRadius;
    qint32 m_radiusSize;
    QList<qint32> m_fightProperties;
    QList<qint32> m_worldProperties;
    QList<qint16> m_naturalStates;
    QList<SpellInfo> m_spellsIdAndLevel;
    qint8 m_familyRank;
    qint16 m_walkingSpeed;
    qint16 m_runningSpeed;
    qint16 m_runningRadiusInWorld;
    qint16 m_runningRadiusInFight;
    QList<MonsterAction> m_monsterActionData;
    QList<MonsterCollectActionData> m_monsterCollectActionData;
    QList<MonsterBehaviourData> m_monsterBehaviourData;
    QList<MonsterEvolutionData> m_monsterEvolutionData;
    qint32 m_requiredLeadershipPoints;
    qint16 m_alignmentId;
    qint32 m_timelineBuffId;
    qint32 m_monsterHeight;
    qint32 m_defeatScriptId;
    QList<qint32> m_gfxEquipment;
    QList<Equipement> m_specialGfxEquipement;
    QList<MonsterColor> m_specialGfxColor;
    QList<Anim> m_specialGfxAnim;
    qint32 m_gfx;
    qint32 m_timelineGfx;
};

class Monster : public BaseBinaryReader
{
public:
    Monster() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            MonsterBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_familyId = r->ReadInt("m_familyId");
            entry.m_levelMin = r->ReadShort("m_levelMin");
            entry.m_levelMax = r->ReadShort("m_levelMax");
            entry.m_xpMultiplicator = r->ReadFloat("m_xpMultiplicator");
            entry.m_arcadePointsMultiplicator = r->ReadFloat("m_arcadePointsMultiplicator");
            entry.m_baseHp = r->ReadInt("m_baseHp");
            entry.m_baseWp = r->ReadInt("m_baseWp");
            entry.m_baseAp = r->ReadInt("m_baseAp");
            entry.m_baseMp = r->ReadInt("m_baseMp");
            entry.m_baseRange = r->ReadInt("m_baseRange");
            entry.m_baseInit = r->ReadInt("m_baseInit");
            entry.m_basePerception = r->ReadInt("m_basePerception");
            entry.m_baseParade = r->ReadInt("m_baseParade");
            entry.m_baseWill = r->ReadInt("m_baseWill");
            entry.m_baseCriticalHit = r->ReadInt("m_baseCriticalHit");
            entry.m_baseTimeBeforeDeath = r->ReadInt("m_baseTimeBeforeDeath");
            entry.m_HpInc = r->ReadFloat("m_HpInc");
            entry.m_WpInc = r->ReadFloat("m_WpInc");
            entry.m_ApInc = r->ReadFloat("m_ApInc");
            entry.m_MpInc = r->ReadFloat("m_MpInc");
            entry.m_rangeInc = r->ReadFloat("m_rangeInc");
            entry.m_initInc = r->ReadFloat("m_initInc");
            entry.m_perceptionInc = r->ReadFloat("m_perceptionInc");
            entry.m_paradeInc = r->ReadFloat("m_paradeInc");
            entry.m_willInc = r->ReadFloat("m_willInc");
            entry.m_CriticalHitInc = r->ReadFloat("m_CriticalHitInc");
            entry.m_baseHealingBonus = r->ReadInt("m_baseHealingBonus");
            entry.m_baseSummonBonus = r->ReadInt("m_baseSummonBonus");
            entry.m_baseMechanicsBonus = r->ReadInt("m_baseMechanicsBonus");
            entry.m_baseTackleBonus = r->ReadInt("m_baseTackleBonus");
            entry.m_baseFireDamageBonus = r->ReadInt("m_baseFireDamageBonus");
            entry.m_baseWaterDamageBonus = r->ReadInt("m_baseWaterDamageBonus");
            entry.m_baseEarthDamageBonus = r->ReadInt("m_baseEarthDamageBonus");
            entry.m_baseWindDamageBonus = r->ReadInt("m_baseWindDamageBonus");
            entry.m_baseFireResistance = r->ReadInt("m_baseFireResistance");
            entry.m_baseWaterResistance = r->ReadInt("m_baseWaterResistance");
            entry.m_baseEarthResistance = r->ReadInt("m_baseEarthResistance");
            entry.m_baseWindResistance = r->ReadInt("m_baseWindResistance");
            entry.m_baseTackleResistance = r->ReadInt("m_baseTackleResistance");
            entry.m_baseAPLossResistance = r->ReadInt("m_baseAPLossResistance");
            entry.m_basePMLossResistance = r->ReadInt("m_basePMLossResistance");
            entry.m_baseWPLossResistance = r->ReadInt("m_baseWPLossResistance");
            entry.m_healingBonusInc = r->ReadFloat("m_healingBonusInc");
            entry.m_tackleBonusInc = r->ReadFloat("m_tackleBonusInc");
            entry.m_fireDamageBonusInc = r->ReadFloat("m_fireDamageBonusInc");
            entry.m_waterDamageBonusInc = r->ReadFloat("m_waterDamageBonusInc");
            entry.m_earthDamageBonusInc = r->ReadFloat("m_earthDamageBonusInc");
            entry.m_windDamageBonusInc = r->ReadFloat("m_windDamageBonusInc");
            entry.m_fireResistanceInc = r->ReadFloat("m_fireResistanceInc");
            entry.m_waterResistanceInc = r->ReadFloat("m_waterResistanceInc");
            entry.m_earthResistanceInc = r->ReadFloat("m_earthResistanceInc");
            entry.m_windResistanceInc = r->ReadFloat("m_windResistanceInc");
            entry.m_tackleResistanceInc = r->ReadFloat("m_tackleResistanceInc");
            entry.m_apLossResistanceInc = r->ReadFloat("m_apLossResistanceInc");
            entry.m_pmLossResistanceInc = r->ReadFloat("m_pmLossResistanceInc");
            entry.m_wpLossResistanceInc = r->ReadFloat("m_wpLossResistanceInc");
            entry.m_hasDeadEvolution = r->ReadBool("m_hasDeadEvolution");
            entry.m_npcRank = r->ReadShort("m_npcRank");
            entry.m_agroRadius = r->ReadShort("m_agroRadius");
            entry.m_sightRadius = r->ReadShort("m_sightRadius");
            entry.m_radiusSize = r->ReadInt("m_radiusSize");
            entry.m_fightProperties = r->ReadIntArray("m_fightProperties");
            entry.m_worldProperties = r->ReadIntArray("m_worldProperties");
            entry.m_naturalStates = r->ReadShortArray("m_naturalStates");

            qint32 spellsIdAndLevelCount = r->ReadInt();

            for (qint32 i = 0; i < spellsIdAndLevelCount; ++i)
            {
                SpellInfo spellInfo;

                spellInfo.m_id = r->ReadInt();
                spellInfo.m_level = r->ReadInt();

                entry.m_spellsIdAndLevel.push_back(spellInfo);
            }

            entry.m_familyRank = r->ReadByte("m_familyRank");
            entry.m_walkingSpeed = r->ReadShort("m_walkingSpeed");
            entry.m_runningSpeed = r->ReadShort("m_runningSpeed");
            entry.m_runningRadiusInWorld = r->ReadShort("m_runningRadiusInWorld");
            entry.m_runningRadiusInFight = r->ReadShort("m_runningRadiusInFight");

            qint32 monsterActionDataCount = r->ReadInt();

            for (qint32 i = 0; i < monsterActionDataCount; ++i)
            {
                MonsterAction monsterAction;

                monsterAction.m_id = r->ReadInt();
                monsterAction.m_type = r->ReadByte();
                monsterAction.m_criteria = r->ReadString();
                monsterAction.m_criteriaOnNpc = r->ReadBool();
                monsterAction.m_moveToMonsterBeforeInteractWithHim = r->ReadBool();
                monsterAction.m_duration = r->ReadInt();
                monsterAction.m_showProgressBar = r->ReadBool();
                monsterAction.m_visualId = r->ReadInt();
                monsterAction.m_scriptId = r->ReadInt();

                entry.m_monsterActionData.push_back(monsterAction);
            }


            qint32 monsterCollectActionDataCount = r->ReadInt();

            for (qint32 i = 0; i < monsterCollectActionDataCount; ++i)
            {
                MonsterCollectActionData monsterCollectActionData;

                monsterCollectActionData.m_id = r->ReadInt();
                monsterCollectActionData.m_skillId = r->ReadInt();
                monsterCollectActionData.m_skillLevelRequired = r->ReadInt();
                monsterCollectActionData.m_skillVisualFeedbackId = r->ReadInt();
                monsterCollectActionData.m_criteria = r->ReadString();
                monsterCollectActionData.m_xpFactor = r->ReadFloat();
                monsterCollectActionData.m_collectLootListId = r->ReadInt();
                monsterCollectActionData.m_duration = r->ReadInt();
                monsterCollectActionData.m_collectItemId = r->ReadInt();
                monsterCollectActionData.m_lootList = r->ReadIntArray();
                monsterCollectActionData.m_displayInCraftDialog = r->ReadBool();

                entry.m_monsterCollectActionData.push_back(monsterCollectActionData);
            }


            qint32 monsterBehaviourDataCount = r->ReadInt();

            for (qint32 i = 0; i < monsterBehaviourDataCount; ++i)
            {
                MonsterBehaviourData monsterBehaviourData;

                monsterBehaviourData.m_id = r->ReadInt();
                monsterBehaviourData.m_type = r->ReadInt();
                monsterBehaviourData.m_scriptId = r->ReadInt();
                monsterBehaviourData.m_needsToWaitPathEnd = r->ReadBool();

                entry.m_monsterBehaviourData.push_back(monsterBehaviourData);
            }


            qint32 monsterEvolutionDataCount = r->ReadInt();

            for (qint32 i = 0; i < monsterEvolutionDataCount; ++i)
            {
                MonsterEvolutionData monsterEvolutionData;

                monsterEvolutionData.m_id = r->ReadInt();
                monsterEvolutionData.m_breedId = r->ReadInt();
                monsterEvolutionData.m_scriptId = r->ReadInt();

                entry.m_monsterEvolutionData.push_back(monsterEvolutionData);
            }

            entry.m_requiredLeadershipPoints = r->ReadInt("m_requiredLeadershipPoints");
            entry.m_alignmentId = r->ReadShort("m_alignmentId");
            entry.m_timelineBuffId = r->ReadInt("m_timelineBuffId");
            entry.m_monsterHeight = r->ReadInt("m_monsterHeight");
            entry.m_defeatScriptId = r->ReadInt("m_defeatScriptId");
            entry.m_gfxEquipment = r->ReadIntArray("m_gfxEquipment");

            qint32 specialGfxEquipementCount = r->ReadInt();

            for (qint32 i = 0; i < specialGfxEquipementCount; ++i)
            {
                Equipement equipement;

                equipement.m_fileId = r->ReadString();
                equipement.m_parts = r->ReadStringArray();

                entry.m_specialGfxEquipement.push_back(equipement);
            }


            qint32 specialGfxColorCount = r->ReadInt();

            for (qint32 i = 0; i < specialGfxColorCount; ++i)
            {
                MonsterColor color;

                color.m_partIndex = r->ReadInt();
                color.m_color = r->ReadInt();

                entry.m_specialGfxColor.push_back(color);
            }


            qint32 specialGfxAnimCount = r->ReadInt();

            for (qint32 i = 0; i < specialGfxAnimCount; ++i)
            {
                Anim anim;

                anim.m_key = r->ReadByte();
                anim.m_animName = r->ReadString();

                entry.m_specialGfxAnim.push_back(anim);
            }

            entry.m_gfx = r->ReadInt("m_gfx");
            entry.m_timelineGfx = r->ReadInt("m_timelineGfx");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif