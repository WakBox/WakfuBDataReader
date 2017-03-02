#include "BaseBinaryReader.h"

struct DungeonBinaryData
{
    qint32 m_id;
    qint16 m_minLevel;
    qint16 m_instanceId;
    QList<qint32> m_tps;
};

class Dungeon : public BaseBinaryReader
{
public:
    Dungeon() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            DungeonBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_minLevel = r->ReadShort("m_minLevel");
            entry.m_instanceId = r->ReadShort("m_instanceId");
            entry.m_tps = r->ReadIntArray("m_tps");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};