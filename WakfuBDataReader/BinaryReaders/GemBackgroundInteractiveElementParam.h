#ifndef GEMBACKGROUNDINTERACTIVEELEMENTPARAM_H
#define GEMBACKGROUNDINTERACTIVEELEMENTPARAM_H

#include "BaseBinaryReader.h"

struct GemBackgroundInteractiveElementParamBinaryData
{
    qint32 m_id;
    qint32 m_backgroundFeedback;
    QList<qint32> m_havreGemTypes;
};

class GemBackgroundInteractiveElementParam : public BaseBinaryReader
{
public:
    GemBackgroundInteractiveElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            GemBackgroundInteractiveElementParamBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_backgroundFeedback = r->ReadInt("m_backgroundFeedback");
            entry.m_havreGemTypes = r->ReadIntArray("m_havreGemTypes");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif