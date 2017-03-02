#include "BaseBinaryReader.h"

struct DecorationInteractiveElementParamBinaryData
{
    qint32 m_id;
    QList<qint32> m_havreGemTypes;
};

class DecorationInteractiveElementParam : public BaseBinaryReader
{
public:
    DecorationInteractiveElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            DecorationInteractiveElementParamBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_havreGemTypes = r->ReadIntArray("m_havreGemTypes");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};