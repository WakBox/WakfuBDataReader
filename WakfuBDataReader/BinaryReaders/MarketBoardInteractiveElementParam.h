#include "BaseBinaryReader.h"

struct MarketBoardInteractiveElementParamBinaryData
{
    qint32 m_id;
    qint32 m_visualMruId;
    qint32 m_marketId;
    qint8 if (buffer.get() != 0) {;
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
            entry.if (buffer.get() != 0) { = r->ReadByte("if (buffer.get() != 0) {");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};