#include "BaseBinaryReader.h"

struct HavenBagModelViewBinaryData
{
    qint32 m_id;
    bool m_restrictionWorld;
    bool m_restrictionMarket;
    qint32 m_backgroundMapId;
    bool m_innate;
};

class HavenBagModelView : public BaseBinaryReader
{
public:
    HavenBagModelView() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            HavenBagModelViewBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_restrictionWorld = r->ReadBool("m_restrictionWorld");
            entry.m_restrictionMarket = r->ReadBool("m_restrictionMarket");
            entry.m_backgroundMapId = r->ReadInt("m_backgroundMapId");
            entry.m_innate = r->ReadBool("m_innate");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};