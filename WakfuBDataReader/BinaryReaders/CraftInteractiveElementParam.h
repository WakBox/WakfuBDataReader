#include "BaseBinaryReader.h"
#include "ChaosParam.h"

struct CraftInteractiveElementParamBinaryData
{
    qint32 m_id;
    qint32 m_apsId;
    qint32 m_visualMruId;
    qint32 m_skillId;
    QList<qint32> m_allowedRecipes;
    ChaosParamBinaryData m_chaosParams;
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
