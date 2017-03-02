#include "BaseBinaryReader.h"

struct AptitudeBonusCategoryBinaryData
{
    qint32 m_categoryId;
    QList<qint32> m_levels;
    QList<qint32> m_bonusIds;
};

class AptitudeBonusCategory : public BaseBinaryReader
{
public:
    AptitudeBonusCategory() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            AptitudeBonusCategoryBinaryData entry;

            entry.m_categoryId = r->ReadInt("m_categoryId");
            entry.m_levels = r->ReadIntArray("m_levels");
            entry.m_bonusIds = r->ReadIntArray("m_bonusIds");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};