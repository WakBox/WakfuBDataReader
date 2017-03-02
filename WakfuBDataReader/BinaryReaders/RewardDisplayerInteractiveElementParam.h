#ifndef REWARDDISPLAYERINTERACTIVEELEMENTPARAM_H
#define REWARDDISPLAYERINTERACTIVEELEMENTPARAM_H

#include "BaseBinaryReader.h"

struct RewardDisplayerInteractiveElementParamBinaryData
{
    qint32 m_id;
    QList<qint32> m_itemIds;
};

class RewardDisplayerInteractiveElementParam : public BaseBinaryReader
{
public:
    RewardDisplayerInteractiveElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            RewardDisplayerInteractiveElementParamBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_itemIds = r->ReadIntArray("m_itemIds");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif