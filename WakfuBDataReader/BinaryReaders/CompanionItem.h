#ifndef COMPANIONITEM_H
#define COMPANIONITEM_H

#include "BaseBinaryReader.h"

struct CompanionItemBinaryData
{
    qint32 m_id;
};

class CompanionItem : public BaseBinaryReader
{
public:
    CompanionItem() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            CompanionItemBinaryData entry;

            entry.m_id = r->ReadInt("m_id");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif