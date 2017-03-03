#ifndef BOATLINK_H
#define BOATLINK_H

#include "BaseBinaryReader.h"
#include "TravelLoading.h"

struct BoatLinkBinaryData
{
    qint32 m_id;
    qint32 m_start;
    qint32 m_end;
    qint32 m_cost;
    QString m_criteria;
    QString m_criteriaDisplay;
    bool m_needsToPayEverytime;
    TravelLoadingBinaryData m_loading;
};

class BoatLink : public BaseBinaryReader
{
public:
    BoatLink() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            BoatLinkBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_start = r->ReadInt("m_start");
            entry.m_end = r->ReadInt("m_end");
            entry.m_cost = r->ReadInt("m_cost");
            entry.m_criteria = r->ReadString("m_criteria");
            entry.m_criteriaDisplay = r->ReadString("m_criteriaDisplay");
            entry.m_needsToPayEverytime = r->ReadBool("m_needsToPayEverytime");

            entry.m_loading.m_loadingAnimationName = r->ReadString("m_loadingAnimationName");
            entry.m_loading.m_loadingMinDuration = r->ReadInt("m_loadingMinDuration");
            entry.m_loading.m_loadingFadeInDuration = r->ReadInt("m_loadingFadeInDuration");
            entry.m_loading.m_loadingFadeOutDuration = r->ReadInt("m_loadingFadeOutDuration");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif
