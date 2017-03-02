#include "BaseBinaryReader.h"

struct MonsterTypeRelashionshipBinaryData
{
    qint32 m_id;
    qint32 m_familyFrom;
    qint32 m_familyTo;
};

class MonsterTypeRelashionship : public BaseBinaryReader
{
public:
    MonsterTypeRelashionship() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            MonsterTypeRelashionshipBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_familyFrom = r->ReadInt("m_familyFrom");
            entry.m_familyTo = r->ReadInt("m_familyTo");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};