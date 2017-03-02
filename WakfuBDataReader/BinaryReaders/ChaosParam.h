#include "BaseBinaryReader.h"

struct ChaosParamBinaryData
{
    qint8 m_chaosLevel;
    qint32 m_chaosCollectorParamId;
};

class ChaosParam : public BaseBinaryReader
{
public:
    ChaosParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            ChaosParamBinaryData entry;

            entry.m_chaosLevel = r->ReadByte("m_chaosLevel");
            entry.m_chaosCollectorParamId = r->ReadInt("m_chaosCollectorParamId");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};