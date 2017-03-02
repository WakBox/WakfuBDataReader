#include "BaseBinaryReader.h"

struct KrosmozFigureBinaryData
{
    qint32 m_id;
    qint32 m_year;
    qint32 m_addon;
    qint32 m_season;
};

class KrosmozFigure : public BaseBinaryReader
{
public:
    KrosmozFigure() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            KrosmozFigureBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_year = r->ReadInt("m_year");
            entry.m_addon = r->ReadInt("m_addon");
            entry.m_season = r->ReadInt("m_season");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};