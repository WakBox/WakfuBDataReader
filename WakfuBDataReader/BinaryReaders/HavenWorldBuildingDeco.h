#ifndef HAVENWORLDBUILDINGDECO_H
#define HAVENWORLDBUILDINGDECO_H

#include "BaseBinaryReader.h"

struct HavenWorldBuildingDecoBinaryData
{
    qint32 m_id;
    qint16 m_catalogEntryId;
    qint32 m_kamaCost;
    qint32 m_ressourceCost;
    qint32 m_editorGroupId;
};

class HavenWorldBuildingDeco : public BaseBinaryReader
{
public:
    HavenWorldBuildingDeco() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            HavenWorldBuildingDecoBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_catalogEntryId = r->ReadShort("m_catalogEntryId");
            entry.m_kamaCost = r->ReadInt("m_kamaCost");
            entry.m_ressourceCost = r->ReadInt("m_ressourceCost");
            entry.m_editorGroupId = r->ReadInt("m_editorGroupId");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif