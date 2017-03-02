#include "BaseBinaryReader.h"

struct KrosmozGameBoardInteractiveElementParamBinaryData
{
    qint32 m_id;
    qint8 m_gameId;
};

class KrosmozGameBoardInteractiveElementParam : public BaseBinaryReader
{
public:
    KrosmozGameBoardInteractiveElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            KrosmozGameBoardInteractiveElementParamBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_gameId = r->ReadByte("m_gameId");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};