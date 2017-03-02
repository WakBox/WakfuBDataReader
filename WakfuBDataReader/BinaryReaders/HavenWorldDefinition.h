#include "BaseBinaryReader.h"

struct HavenWorldDefinitionBinaryData
{
    qint32 m_id;
    qint16 m_worldId;
    qint8 m_workers;
    qint16 m_exitWorldId;
    qint16 m_exitCellX;
    qint16 m_exitCellY;
    qint16 m_exitCellZ;
};

class HavenWorldDefinition : public BaseBinaryReader
{
public:
    HavenWorldDefinition() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            HavenWorldDefinitionBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_worldId = r->ReadShort("m_worldId");
            entry.m_workers = r->ReadByte("m_workers");
            entry.m_exitWorldId = r->ReadShort("m_exitWorldId");
            entry.m_exitCellX = r->ReadShort("m_exitCellX");
            entry.m_exitCellY = r->ReadShort("m_exitCellY");
            entry.m_exitCellZ = r->ReadShort("m_exitCellZ");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};