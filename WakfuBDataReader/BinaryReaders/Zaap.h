#ifndef ZAAP_H
#define ZAAP_H

#include "BaseBinaryReader.h"

struct ZaapBinaryData
{
    qint32 m_zaapId;
    qint32 m_exitX;
    qint32 m_exitY;
    qint32 m_exitWorldId;
    qint32 m_visualId;
    qint32 m_uiGfxId;
    qint8 m_landmarkTravelType;
    bool m_zaapBase;
    QString m_destinationCriteria;
    TravelLoadingBinaryData m_loading;
};

class Zaap : public BaseBinaryReader
{
public:
    Zaap() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            ZaapBinaryData entry;

            entry.m_zaapId = r->ReadInt("m_zaapId");
            entry.m_exitX = r->ReadInt("m_exitX");
            entry.m_exitY = r->ReadInt("m_exitY");
            entry.m_exitWorldId = r->ReadInt("m_exitWorldId");
            entry.m_visualId = r->ReadInt("m_visualId");
            entry.m_uiGfxId = r->ReadInt("m_uiGfxId");
            entry.m_landmarkTravelType = r->ReadByte("m_landmarkTravelType");
            entry.m_zaapBase = r->ReadBool("m_zaapBase");
            entry.m_destinationCriteria = r->ReadString("m_destinationCriteria");

            qint8 hasTravelLoading = r->ReadByte("hasTravelLoading");
            if (hasTravelLoading != 0)
            {
                entry.m_loading.m_loadingAnimationName = r->ReadString("m_loadingAnimationName");
                entry.m_loading.m_loadingMinDuration = r->ReadInt("m_loadingMinDuration");
                entry.m_loading.m_loadingFadeInDuration = r->ReadInt("m_loadingFadeInDuration");
                entry.m_loading.m_loadingFadeOutDuration = r->ReadInt("m_loadingFadeOutDuration");
            }

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif