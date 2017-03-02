#ifndef PROTECTORBUFFLIST_H
#define PROTECTORBUFFLIST_H

#include "BaseBinaryReader.h"

struct ProtectorBuffListBinaryData
{
    qint32 m_buffListId;
    QList<qint32> m_buffLists;
};

class ProtectorBuffList : public BaseBinaryReader
{
public:
    ProtectorBuffList() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            ProtectorBuffListBinaryData entry;

            entry.m_buffListId = r->ReadInt("m_buffListId");
            entry.m_buffLists = r->ReadIntArray("m_buffLists");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif