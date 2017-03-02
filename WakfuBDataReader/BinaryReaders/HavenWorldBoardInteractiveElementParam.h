#ifndef HAVENWORLDBOARDINTERACTIVEELEMENTPARAM_H
#define HAVENWORLDBOARDINTERACTIVEELEMENTPARAM_H

#include "BaseBinaryReader.h"

struct HavenWorldBoardInteractiveElementParamBinaryData
{
    qint32 m_id;
    qint32 m_visualId;
    qint16 m_havenWorldId;
    qint16 m_miniOriginCellX;
    qint16 m_miniOriginCellY;
    qint16 m_miniOriginCellZ;
};

class HavenWorldBoardInteractiveElementParam : public BaseBinaryReader
{
public:
    HavenWorldBoardInteractiveElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            HavenWorldBoardInteractiveElementParamBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_visualId = r->ReadInt("m_visualId");
            entry.m_havenWorldId = r->ReadShort("m_havenWorldId");
            entry.m_miniOriginCellX = r->ReadShort("m_miniOriginCellX");
            entry.m_miniOriginCellY = r->ReadShort("m_miniOriginCellY");
            entry.m_miniOriginCellZ = r->ReadShort("m_miniOriginCellZ");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif