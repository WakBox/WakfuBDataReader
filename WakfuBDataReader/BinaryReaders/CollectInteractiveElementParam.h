#ifndef COLLECTINTERACTIVEELEMENTPARAM_H
#define COLLECTINTERACTIVEELEMENTPARAM_H

#include "BaseBinaryReader.h"

struct CollectItem
{
    qint32 m_uid;
    qint32 m_itemId;
    qint32 m_qty;
};

struct CollectAction
{
    qint32 m_actionId;
    qint32 m_actionType;
    QList<QString> m_params;
    QString m_criteria;
};

struct CollectInteractiveElementParamBinaryData
{
    qint32 m_id;
    qint32 m_visualId;
    qint16 m_capacity;
    bool m_locked;
    qint32 m_cashQty;
    QList<CollectItem> m_items;
    QList<CollectAction> m_actions;
};

class CollectInteractiveElementParam : public BaseBinaryReader
{
public:
    CollectInteractiveElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            CollectInteractiveElementParamBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_visualId = r->ReadInt("m_visualId");
            entry.m_capacity = r->ReadShort("m_capacity");
            entry.m_locked = r->ReadBool("m_locked");
            entry.m_cashQty = r->ReadInt("m_cashQty");

            qint32 itemCount = r->ReadInt();

            for (qint32 i = 0; i < itemCount; ++i)
            {
                CollectItem collectItem;

                collectItem.m_uid = r->ReadInt();
                collectItem.m_itemId = r->ReadInt();
                collectItem.m_qty = r->ReadInt();

                entry.m_items.push_back(collectItem);
            }


            qint32 actionCount = r->ReadInt();

            for (qint32 i = 0; i < actionCount; ++i)
            {
                CollectAction collectAction;

                collectAction.m_actionId = r->ReadInt();
                collectAction.m_actionType = r->ReadInt();
                collectAction.m_params = r->ReadStringArray();
                collectAction.m_criteria = r->ReadString();

                entry.m_actions.push_back(collectAction);
            }


            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif