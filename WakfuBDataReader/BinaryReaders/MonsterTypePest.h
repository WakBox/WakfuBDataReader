#ifndef MONSTERTYPEPEST_H
#define MONSTERTYPEPEST_H

#include "BaseBinaryReader.h"

struct MonsterTypePestBinaryData
{
    qint32 m_id;
    qint32 m_familyId;
    qint32 m_pestMonsterId;
};

class MonsterTypePest : public BaseBinaryReader
{
public:
    MonsterTypePest() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            MonsterTypePestBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_familyId = r->ReadInt("m_familyId");
            entry.m_pestMonsterId = r->ReadInt("m_pestMonsterId");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif