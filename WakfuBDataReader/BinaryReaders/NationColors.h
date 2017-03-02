#include "BaseBinaryReader.h"

struct NationColorsBinaryData
{
    qint32 m_id;
    QString m_color;
};

class NationColors : public BaseBinaryReader
{
public:
    NationColors() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            NationColorsBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_color = r->ReadString("m_color");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};