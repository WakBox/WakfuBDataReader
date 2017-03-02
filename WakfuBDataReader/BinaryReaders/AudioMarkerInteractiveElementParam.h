#ifndef AUDIOMARKERINTERACTIVEELEMENTPARAM_H
#define AUDIOMARKERINTERACTIVEELEMENTPARAM_H

#include "BaseBinaryReader.h"

struct AudioMarkerInteractiveElementParamBinaryData
{
    qint32 m_id;
    qint32 m_audioMarkerTypeId;
    bool m_isLocalized;
};

class AudioMarkerInteractiveElementParam : public BaseBinaryReader
{
public:
    AudioMarkerInteractiveElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            AudioMarkerInteractiveElementParamBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_audioMarkerTypeId = r->ReadInt("m_audioMarkerTypeId");
            entry.m_isLocalized = r->ReadBool("m_isLocalized");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif