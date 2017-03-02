#ifndef ITEM_H
#define ITEM_H

#include "BaseBinaryReader.h"

struct ItemAction
{
    qint32 m_actionId;
    qint32 m_actionTypeId;
    bool m_consumeItemOnAction;
    bool m_clientOnly;
    bool m_stopMovement;
    bool m_hasScript;
    QString m_criteria;
    QList<QString> m_actionParams;
    QList<QString> m_actionScriptParams;
};

struct ItemBinaryData
{
    qint32 m_id;
    qint32 m_metaId;
    qint16 m_itemSetId;
    qint32 m_gfxId;
    qint32 m_femaleGfxId;
    qint32 m_floorGfxId;
    qint16 m_level;
    QList<QString> m_criteria;
    qint32 m_itemTypeId;
    qint16 m_maxStackHeight;
    qint8 m_useCostAP;
    qint8 m_useCostMP;
    qint8 m_useCostFP;
    qint32 m_useRangeMin;
    qint32 m_useRangeMax;
    bool m_useTestFreeCell;
    bool m_useTestNotBorderCell;
    bool m_useTestLos;
    bool m_useTestOnlyLine;
    qint16 m_itemRarity;
    qint8 m_itemBindType;
    QString m_generationType;
    QList<qint32> m_itemProperties;
    qint8 m_itemActionVisual;
    qint8 m_worldUsageTarget;
    qint8 m_gemElementType;
    qint8 m_gemNum;
    QList<qint32> m_effectIds;
    QList<ItemAction> m_actions;
    QList<qint32> m_subMetaIds;
    QList<qint8> m_gemSlots;
    QList<qint8> m_gemSlotType;
};

class Item : public BaseBinaryReader
{
public:
    Item() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            ItemBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_metaId = r->ReadInt("m_metaId");
            entry.m_itemSetId = r->ReadShort("m_itemSetId");
            entry.m_gfxId = r->ReadInt("m_gfxId");
            entry.m_femaleGfxId = r->ReadInt("m_femaleGfxId");
            entry.m_floorGfxId = r->ReadInt("m_floorGfxId");
            entry.m_level = r->ReadShort("m_level");
            entry.m_criteria = r->ReadStringArray("m_criteria");
            entry.m_itemTypeId = r->ReadInt("m_itemTypeId");
            entry.m_maxStackHeight = r->ReadShort("m_maxStackHeight");
            entry.m_useCostAP = r->ReadByte("m_useCostAP");
            entry.m_useCostMP = r->ReadByte("m_useCostMP");
            entry.m_useCostFP = r->ReadByte("m_useCostFP");
            entry.m_useRangeMin = r->ReadInt("m_useRangeMin");
            entry.m_useRangeMax = r->ReadInt("m_useRangeMax");
            entry.m_useTestFreeCell = r->ReadBool("m_useTestFreeCell");
            entry.m_useTestNotBorderCell = r->ReadBool("m_useTestNotBorderCell");
            entry.m_useTestLos = r->ReadBool("m_useTestLos");
            entry.m_useTestOnlyLine = r->ReadBool("m_useTestOnlyLine");
            entry.m_itemRarity = r->ReadShort("m_itemRarity");
            entry.m_itemBindType = r->ReadByte("m_itemBindType");
            entry.m_generationType = r->ReadString("m_generationType");
            entry.m_itemProperties = r->ReadIntArray("m_itemProperties");
            entry.m_itemActionVisual = r->ReadByte("m_itemActionVisual");
            entry.m_worldUsageTarget = r->ReadByte("m_worldUsageTarget");
            entry.m_gemElementType = r->ReadByte("m_gemElementType");
            entry.m_gemNum = r->ReadByte("m_gemNum");
            entry.m_effectIds = r->ReadIntArray("m_effectIds");

            qint32 actionCount = r->ReadInt();

            for (qint32 i = 0; i < actionCount; ++i)
            {
                ItemAction itemAction;

                itemAction.m_actionId = r->ReadInt();
                itemAction.m_actionTypeId = r->ReadInt();
                itemAction.m_consumeItemOnAction = r->ReadBool();
                itemAction.m_clientOnly = r->ReadBool();
                itemAction.m_stopMovement = r->ReadBool();
                itemAction.m_hasScript = r->ReadBool();
                itemAction.m_criteria = r->ReadString();
                itemAction.m_actionParams = r->ReadStringArray();
                itemAction.m_actionScriptParams = r->ReadStringArray();

                entry.m_actions.push_back(itemAction);
            }

            entry.m_subMetaIds = r->ReadIntArray("m_subMetaIds");
            entry.m_gemSlots = r->ReadByteArray("m_gemSlots");
            entry.m_gemSlotType = r->ReadByteArray("m_gemSlotType");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif