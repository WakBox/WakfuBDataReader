#ifndef HAVENWORLDPATCHDEFINITION_H
#define HAVENWORLDPATCHDEFINITION_H

#include "BaseBinaryReader.h"

struct HavenWorldPatchDefinitionBinaryData
{
    qint32 m_id;
    qint32 m_patchId;
    qint32 m_kamaCost;
    qint32 m_categoryId;
    qint32 m_soundId;
};

class HavenWorldPatchDefinition : public BaseBinaryReader
{
public:
    HavenWorldPatchDefinition() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            HavenWorldPatchDefinitionBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_patchId = r->ReadInt("m_patchId");
            entry.m_kamaCost = r->ReadInt("m_kamaCost");
            entry.m_categoryId = r->ReadInt("m_categoryId");
            entry.m_soundId = r->ReadInt("m_soundId");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif