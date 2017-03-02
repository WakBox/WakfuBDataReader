#ifndef MONSTERTYPEDUNGEON_H
#define MONSTERTYPEDUNGEON_H

#include "BaseBinaryReader.h"

struct MonsterTypeDungeonBinaryData
{
    qint32 m_id;
    qint32 m_familyId;
    qint32 m_dungeonId;
    qint16 m_level;
};

class MonsterTypeDungeon : public BaseBinaryReader
{
public:
    MonsterTypeDungeon() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            MonsterTypeDungeonBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_familyId = r->ReadInt("m_familyId");
            entry.m_dungeonId = r->ReadInt("m_dungeonId");
            entry.m_level = r->ReadShort("m_level");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif