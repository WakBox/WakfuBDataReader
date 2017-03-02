#ifndef STREETLIGHTINTERACTIVEELEMENTPARAM_H
#define STREETLIGHTINTERACTIVEELEMENTPARAM_H

#include "BaseBinaryReader.h"

struct StreetLightInteractiveElementParamBinaryData
{
    qint32 m_id;
    qint32 m_color;
    float m_range;
    qint32 m_apsId;
    bool m_activeOnlyInNight;
    qint32 m_ignitionVisualId;
    bool m_ignitionUseObject;
    qint32 m_ignitionDuration;
    qint32 m_extinctionVisualId;
    bool m_extinctionUseObject;
    qint32 m_extinctionDuration;
    ChaosParamBinaryData m_chaosParams;
};

class StreetLightInteractiveElementParam : public BaseBinaryReader
{
public:
    StreetLightInteractiveElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            StreetLightInteractiveElementParamBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_color = r->ReadInt("m_color");
            entry.m_range = r->ReadFloat("m_range");
            entry.m_apsId = r->ReadInt("m_apsId");
            entry.m_activeOnlyInNight = r->ReadBool("m_activeOnlyInNight");
            entry.m_ignitionVisualId = r->ReadInt("m_ignitionVisualId");
            entry.m_ignitionUseObject = r->ReadBool("m_ignitionUseObject");
            entry.m_ignitionDuration = r->ReadInt("m_ignitionDuration");
            entry.m_extinctionVisualId = r->ReadInt("m_extinctionVisualId");
            entry.m_extinctionUseObject = r->ReadBool("m_extinctionUseObject");
            entry.m_extinctionDuration = r->ReadInt("m_extinctionDuration");

            qint8 hasChaosParam = r->ReadByte("hasChaosParams");
            if (hasChaosParam != 0)
            {
                entry.m_chaosParams.m_chaosLevel = r->ReadByte("m_chaosLevel");
                entry.m_chaosParams.m_chaosCollectorParamId = r->ReadInt("m_chaosCollectorParamId");
            }

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif