#ifndef CLIMATEBONUS_H
#define CLIMATEBONUS_H

#include "BaseBinaryReader.h"

struct ClimateBonusBinaryData
{
    qint32 m_buffId;
    qint32 m_gfxId;
    QString m_criteria;
    qint32 m_duration;
    qint16 m_price;
    float m_temperatureDifference;
    float m_rainDifference;
    float m_windDifference;
};

class ClimateBonus : public BaseBinaryReader
{
public:
    ClimateBonus() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            ClimateBonusBinaryData entry;

            entry.m_buffId = r->ReadInt("m_buffId");
            entry.m_gfxId = r->ReadInt("m_gfxId");
            entry.m_criteria = r->ReadString("m_criteria");
            entry.m_duration = r->ReadInt("m_duration");
            entry.m_price = r->ReadShort("m_price");
            entry.m_temperatureDifference = r->ReadFloat("m_temperatureDifference");
            entry.m_rainDifference = r->ReadFloat("m_rainDifference");
            entry.m_windDifference = r->ReadFloat("m_windDifference");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif