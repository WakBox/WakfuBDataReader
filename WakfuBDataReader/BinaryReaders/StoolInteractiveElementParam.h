#include "BaseBinaryReader.h"

struct StoolInteractiveElementParamBinaryData
{
    qint32 m_id;
    QString m_criterion;
    qint32 m_visualId;
    qint8 if (buffer.get() != 0) {;
};

class StoolInteractiveElementParam : public BaseBinaryReader
{
public:
    StoolInteractiveElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            StoolInteractiveElementParamBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_criterion = r->ReadString("m_criterion");
            entry.m_visualId = r->ReadInt("m_visualId");
            entry.if (buffer.get() != 0) { = r->ReadByte("if (buffer.get() != 0) {");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};