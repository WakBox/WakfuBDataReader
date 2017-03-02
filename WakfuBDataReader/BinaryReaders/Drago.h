#include "BaseBinaryReader.h"

struct DragoBinaryData
{
    qint32 m_dragoId;
    qint32 m_exitX;
    qint32 m_exitY;
    qint32 m_visualId;
    qint32 m_uiGfxId;
    QString m_dragoCriterion;
    qint8 m_landmarkTravelType;
    TravelLoadingBinaryData m_loading;
};

class Drago : public BaseBinaryReader
{
public:
    Drago() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            DragoBinaryData entry;

            entry.m_dragoId = r->ReadInt("m_dragoId");
            entry.m_exitX = r->ReadInt("m_exitX");
            entry.m_exitY = r->ReadInt("m_exitY");
            entry.m_visualId = r->ReadInt("m_visualId");
            entry.m_uiGfxId = r->ReadInt("m_uiGfxId");
            entry.m_dragoCriterion = r->ReadString("m_dragoCriterion");
            entry.m_landmarkTravelType = r->ReadByte("m_landmarkTravelType");

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
