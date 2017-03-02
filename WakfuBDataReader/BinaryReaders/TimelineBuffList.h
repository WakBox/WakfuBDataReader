#ifndef TIMELINEBUFFLIST_H
#define TIMELINEBUFFLIST_H

#include "BaseBinaryReader.h"

struct TimelineBuffListBinaryData
{
    qint32 m_id;
    qint32 m_typeId;
    qint32 m_gfxId;
    bool m_forPlayer;
    QList<qint32> m_effectIds;
};

class TimelineBuffList : public BaseBinaryReader
{
public:
    TimelineBuffList() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            TimelineBuffListBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_typeId = r->ReadInt("m_typeId");
            entry.m_gfxId = r->ReadInt("m_gfxId");
            entry.m_forPlayer = r->ReadBool("m_forPlayer");
            entry.m_effectIds = r->ReadIntArray("m_effectIds");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif