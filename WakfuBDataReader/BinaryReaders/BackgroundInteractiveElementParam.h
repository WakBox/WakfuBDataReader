#include "BaseBinaryReader.h"

struct ChaosParamBinaryData;

struct BackgroundInteractiveElementParamBinaryData
{
    qint32 m_id;
    qint32 m_visualId;
    qint32 m_backgroundFeedback;
    ChaosParamBinaryData m_chaosParams;
};

class BackgroundInteractiveElementParam : public BaseBinaryReader
{
public:
    BackgroundInteractiveElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            BackgroundInteractiveElementParamBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_visualId = r->ReadInt("m_visualId");
            entry.m_backgroundFeedback = r->ReadInt("m_backgroundFeedback");

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
