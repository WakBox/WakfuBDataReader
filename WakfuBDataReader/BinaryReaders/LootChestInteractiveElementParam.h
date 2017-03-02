#ifndef LOOTCHESTINTERACTIVEELEMENTPARAM_H
#define LOOTCHESTINTERACTIVEELEMENTPARAM_H

#include "BaseBinaryReader.h"

struct LootChestInteractiveElementParamBinaryData
{
    qint32 m_id;
    qint32 m_visualId;
    qint32 m_cooldown;
    qint32 m_cost;
    qint32 m_itemIdCost;
    qint32 m_itemQuantityCost;
    bool m_doConsumeItem;
    qint32 m_nbActivation;
    qint32 m_distributionDuration;
    QString m_criteria;
    ChaosParamBinaryData m_chaosParams;
};

class LootChestInteractiveElementParam : public BaseBinaryReader
{
public:
    LootChestInteractiveElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            LootChestInteractiveElementParamBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_visualId = r->ReadInt("m_visualId");
            entry.m_cooldown = r->ReadInt("m_cooldown");
            entry.m_cost = r->ReadInt("m_cost");
            entry.m_itemIdCost = r->ReadInt("m_itemIdCost");
            entry.m_itemQuantityCost = r->ReadInt("m_itemQuantityCost");
            entry.m_doConsumeItem = r->ReadBool("m_doConsumeItem");
            entry.m_nbActivation = r->ReadInt("m_nbActivation");
            entry.m_distributionDuration = r->ReadInt("m_distributionDuration");
            entry.m_criteria = r->ReadString("m_criteria");

            qint8 hasChaosParam = r->ReadByte("hasChaosParams");
            if (hasChaosParam != 0)
            {
                entry.m_chaosParams.m_chaosLevel = r->ReadByte("m_chaosLevel");
                entry.m_chaosParams.m_chaosCollectorParamId = r->ReadInt("m_chaosCollectorParamId");
            }

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif