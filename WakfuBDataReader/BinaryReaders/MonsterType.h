#ifndef MONSTERTYPE_H
#define MONSTERTYPE_H

#include "BaseBinaryReader.h"

struct MonsterTypeBinaryData
{
    qint32 m_id;
    qint32 m_parentId;
    qint8 m_type;
};

class MonsterType : public BaseBinaryReader
{
public:
    MonsterType() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            MonsterTypeBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_parentId = r->ReadInt("m_parentId");
            entry.m_type = r->ReadByte("m_type");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif