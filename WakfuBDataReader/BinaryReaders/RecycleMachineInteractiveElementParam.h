#include "BaseBinaryReader.h"

struct RecycleMachineInteractiveElementParamBinaryData
{
    qint32 m_id;
    qint32 m_visualMruId;
    qint8 if (buffer.get() != 0) {;
};

class RecycleMachineInteractiveElementParam : public BaseBinaryReader
{
public:
    RecycleMachineInteractiveElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            RecycleMachineInteractiveElementParamBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_visualMruId = r->ReadInt("m_visualMruId");
            entry.if (buffer.get() != 0) { = r->ReadByte("if (buffer.get() != 0) {");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};