#ifndef DOORINTERACTIVEELEMENTPARAM_H
#define DOORINTERACTIVEELEMENTPARAM_H

#include "BaseBinaryReader.h"

struct DoorInteractiveElementParamBinaryData
{
    qint32 m_id;
    qint32 m_visualId;
    bool m_consumeItem;
    qint32 m_itemNeeded;
    qint32 m_kamaCost;
    QString m_criterion;
};

class DoorInteractiveElementParam : public BaseBinaryReader
{
public:
    DoorInteractiveElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            DoorInteractiveElementParamBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_visualId = r->ReadInt("m_visualId");
            entry.m_consumeItem = r->ReadBool("m_consumeItem");
            entry.m_itemNeeded = r->ReadInt("m_itemNeeded");
            entry.m_kamaCost = r->ReadInt("m_kamaCost");
            entry.m_criterion = r->ReadString("m_criterion");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif