#ifndef BOAT_H
#define BOAT_H

#include "BaseBinaryReader.h"

struct BoatBinaryData
{
    qint32 m_boatId;
    qint32 m_exitX;
    qint32 m_exitY;
    qint32 m_exitWorldId;
    qint32 m_visualId;
    qint32 m_uiGfxId;
    qint8 m_landmarkTravelType;
};

class Boat : public BaseBinaryReader
{
public:
    Boat() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            BoatBinaryData entry;

            entry.m_boatId = r->ReadInt("m_boatId");
            entry.m_exitX = r->ReadInt("m_exitX");
            entry.m_exitY = r->ReadInt("m_exitY");
            entry.m_exitWorldId = r->ReadInt("m_exitWorldId");
            entry.m_visualId = r->ReadInt("m_visualId");
            entry.m_uiGfxId = r->ReadInt("m_uiGfxId");
            entry.m_landmarkTravelType = r->ReadByte("m_landmarkTravelType");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif