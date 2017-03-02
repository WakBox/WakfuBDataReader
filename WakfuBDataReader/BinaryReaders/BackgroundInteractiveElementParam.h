#include "BaseBinaryReader.h"

struct BackgroundInteractiveElementParamBinaryData
{
    qint32 m_id;
    qint32 m_visualId;
    qint32 m_backgroundFeedback;
    qint8 if (buffer.get() != 0) {;
};

class BackgroundInteractiveElementParam : public BaseBinaryReader
{
public:
    BackgroundInteractiveElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            BackgroundInteractiveElementParamBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_visualId = r->ReadInt("m_visualId");
            entry.m_backgroundFeedback = r->ReadInt("m_backgroundFeedback");
            entry.if (buffer.get() != 0) { = r->ReadByte("if (buffer.get() != 0) {");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};