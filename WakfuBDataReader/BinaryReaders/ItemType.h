#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include "BaseBinaryReader.h"

struct ItemTypeBinaryData
{
    qint16 m_id;
    qint16 m_parentId;
    bool m_visibleInAnimations;
    bool m_visibleInMarketPlace;
    bool m_recyclable;
    QList<QString> m_equipmentPosition;
    QList<QString> m_disabledEquipementPosition;
    qint16 m_materialType;
    QList<qint32> m_craftIds;
};

class ItemType : public BaseBinaryReader
{
public:
    ItemType() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            ItemTypeBinaryData entry;

            entry.m_id = r->ReadShort("m_id");
            entry.m_parentId = r->ReadShort("m_parentId");
            entry.m_visibleInAnimations = r->ReadBool("m_visibleInAnimations");
            entry.m_visibleInMarketPlace = r->ReadBool("m_visibleInMarketPlace");
            entry.m_recyclable = r->ReadBool("m_recyclable");
            entry.m_equipmentPosition = r->ReadStringArray("m_equipmentPosition");
            entry.m_disabledEquipementPosition = r->ReadStringArray("m_disabledEquipementPosition");
            entry.m_materialType = r->ReadShort("m_materialType");
            entry.m_craftIds = r->ReadIntArray("m_craftIds");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif