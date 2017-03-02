#ifndef ZAAPLINK_H
#define ZAAPLINK_H

#include "BaseBinaryReader.h"

struct ZaapLinkBinaryData
{
    qint32 m_id;
    qint32 m_start;
    qint32 m_end;
    qint32 m_cost;
};

class ZaapLink : public BaseBinaryReader
{
public:
    ZaapLink() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            ZaapLinkBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_start = r->ReadInt("m_start");
            entry.m_end = r->ReadInt("m_end");
            entry.m_cost = r->ReadInt("m_cost");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif