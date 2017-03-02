#include "BaseBinaryReader.h"

struct EffectGroupBinaryData
{
    qint32 m_id;
    QList<qint32> m_effectIds;
};

class EffectGroup : public BaseBinaryReader
{
public:
    EffectGroup() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            EffectGroupBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_effectIds = r->ReadIntArray("m_effectIds");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};