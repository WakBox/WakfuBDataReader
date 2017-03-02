#include "BaseBinaryReader.h"

struct StoolInteractiveElementParamBinaryData
{
    qint32 m_id;
    QString m_criterion;
    qint32 m_visualId;
    ChaosParamBinaryData m_chaosParams;
};

class StoolInteractiveElementParam : public BaseBinaryReader
{
public:
    StoolInteractiveElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            StoolInteractiveElementParamBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_criterion = r->ReadString("m_criterion");
            entry.m_visualId = r->ReadInt("m_visualId");

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
