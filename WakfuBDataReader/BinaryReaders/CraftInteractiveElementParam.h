#include "BaseBinaryReader.h"

struct CraftInteractiveElementParamBinaryData
{
    qint32 m_id;
    qint32 m_apsId;
    qint32 m_visualMruId;
    qint32 m_skillId;
    QList<qint32> m_allowedRecipes;
    qint8 if (buffer.get() != 0) {;
};

class CraftInteractiveElementParam : public BaseBinaryReader
{
public:
    CraftInteractiveElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            CraftInteractiveElementParamBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_apsId = r->ReadInt("m_apsId");
            entry.m_visualMruId = r->ReadInt("m_visualMruId");
            entry.m_skillId = r->ReadInt("m_skillId");
            entry.m_allowedRecipes = r->ReadIntArray("m_allowedRecipes");
            entry.if (buffer.get() != 0) { = r->ReadByte("if (buffer.get() != 0) {");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};