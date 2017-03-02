#ifndef HAVENWORLDBUILDINGEVOLUTION_H
#define HAVENWORLDBUILDINGEVOLUTION_H

#include "BaseBinaryReader.h"

struct HavenWorldBuildingEvolutionBinaryData
{
    qint32 m_id;
    qint16 m_catalogEntryId;
    qint32 m_fromId;
    qint32 m_toId;
    qint64 m_delay;
    qint8 m_order;
};

class HavenWorldBuildingEvolution : public BaseBinaryReader
{
public:
    HavenWorldBuildingEvolution() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            HavenWorldBuildingEvolutionBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_catalogEntryId = r->ReadShort("m_catalogEntryId");
            entry.m_fromId = r->ReadInt("m_fromId");
            entry.m_toId = r->ReadInt("m_toId");
            entry.m_delay = r->ReadLong("m_delay");
            entry.m_order = r->ReadByte("m_order");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif