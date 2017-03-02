#ifndef CITIZENRANK_H
#define CITIZENRANK_H

#include "BaseBinaryReader.h"

struct CitizenRankBinaryData
{
    qint32 m_id;
    qint32 m_cap;
    qint32 m_pdcLossFactor;
    QString m_translationKey;
    QString m_color;
    QList<qint32> m_rules;
};

class CitizenRank : public BaseBinaryReader
{
public:
    CitizenRank() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            CitizenRankBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_cap = r->ReadInt("m_cap");
            entry.m_pdcLossFactor = r->ReadInt("m_pdcLossFactor");
            entry.m_translationKey = r->ReadString("m_translationKey");
            entry.m_color = r->ReadString("m_color");
            entry.m_rules = r->ReadIntArray("m_rules");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif