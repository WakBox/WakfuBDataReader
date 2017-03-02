#include "BaseBinaryReader.h"

struct NationRankBinaryData
{
    qint32 m_id;
    float m_citizenPointLossFactor;
    QString m_criteria;
    qint32 m_citizenScoreLine;
};

class NationRank : public BaseBinaryReader
{
public:
    NationRank() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            NationRankBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_citizenPointLossFactor = r->ReadFloat("m_citizenPointLossFactor");
            entry.m_criteria = r->ReadString("m_criteria");
            entry.m_citizenScoreLine = r->ReadInt("m_citizenScoreLine");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};