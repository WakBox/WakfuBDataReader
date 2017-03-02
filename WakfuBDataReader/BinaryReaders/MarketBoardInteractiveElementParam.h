#ifndef MARKETBOARDINTERACTIVEELEMENTPARAM_H
#define MARKETBOARDINTERACTIVEELEMENTPARAM_H

#include "BaseBinaryReader.h"

struct MarketBoardInteractiveElementParamBinaryData
{
    qint32 m_id;
    qint32 m_visualMruId;
    qint32 m_marketId;
    ChaosParamBinaryData m_chaosParams;
};

class MarketBoardInteractiveElementParam : public BaseBinaryReader
{
public:
    MarketBoardInteractiveElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            MarketBoardInteractiveElementParamBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_visualMruId = r->ReadInt("m_visualMruId");
            entry.m_marketId = r->ReadInt("m_marketId");

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