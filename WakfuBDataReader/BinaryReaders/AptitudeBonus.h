#include "BaseBinaryReader.h"

struct AptitudeBonusBinaryData
{
    qint32 m_bonusId;
    qint32 m_categoryId;
    qint32 m_max;
    qint32 m_gfxId;
    QList<qint32> m_effectIds;
};

class AptitudeBonus : public BaseBinaryReader
{
public:
    AptitudeBonus() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            AptitudeBonusBinaryData entry;

            entry.m_bonusId = r->ReadInt("m_bonusId");
            entry.m_categoryId = r->ReadInt("m_categoryId");
            entry.m_max = r->ReadInt("m_max");
            entry.m_gfxId = r->ReadInt("m_gfxId");
            entry.m_effectIds = r->ReadIntArray("m_effectIds");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};