#ifndef TRAVELLOADING_H
#define TRAVELLOADING_H

#include "BaseBinaryReader.h"

struct TravelLoadingBinaryData
{
    QString m_loadingAnimationName;
    qint32 m_loadingMinDuration;
    qint32 m_loadingFadeInDuration;
    qint32 m_loadingFadeOutDuration;
};

class TravelLoading : public BaseBinaryReader
{
public:
    TravelLoading() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            TravelLoadingBinaryData entry;

            entry.m_loadingAnimationName = r->ReadString("m_loadingAnimationName");
            entry.m_loadingMinDuration = r->ReadInt("m_loadingMinDuration");
            entry.m_loadingFadeInDuration = r->ReadInt("m_loadingFadeInDuration");
            entry.m_loadingFadeOutDuration = r->ReadInt("m_loadingFadeOutDuration");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif