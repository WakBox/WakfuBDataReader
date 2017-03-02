#include "BaseBinaryReader.h"

struct DungeonDisplayerInteractiveElementParamBinaryData
{
    qint32 m_id;
    qint32 m_dungeonId;
};

class DungeonDisplayerInteractiveElementParam : public BaseBinaryReader
{
public:
    DungeonDisplayerInteractiveElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            DungeonDisplayerInteractiveElementParamBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_dungeonId = r->ReadInt("m_dungeonId");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};