#ifndef INTERACTIVEELEMENTMODEL_H
#define INTERACTIVEELEMENTMODEL_H

#include "BaseBinaryReader.h"

struct InteractiveElementModelBinaryData
{
    qint32 m_id;
    qint16 m_type;
    qint32 m_gfx;
    qint32 m_color;
    qint8 m_height;
    qint32 m_particleId;
    qint32 m_particleOffsetZ;
};

class InteractiveElementModel : public BaseBinaryReader
{
public:
    InteractiveElementModel() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            InteractiveElementModelBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_type = r->ReadShort("m_type");
            entry.m_gfx = r->ReadInt("m_gfx");
            entry.m_color = r->ReadInt("m_color");
            entry.m_height = r->ReadByte("m_height");
            entry.m_particleId = r->ReadInt("m_particleId");
            entry.m_particleOffsetZ = r->ReadInt("m_particleOffsetZ");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif