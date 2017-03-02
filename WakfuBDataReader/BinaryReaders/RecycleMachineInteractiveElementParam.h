#ifndef RECYCLEMACHINEINTERACTIVEELEMENTPARAM_H
#define RECYCLEMACHINEINTERACTIVEELEMENTPARAM_H

#include "BaseBinaryReader.h"

struct RecycleMachineInteractiveElementParamBinaryData
{
    qint32 m_id;
    qint32 m_visualMruId;
    ChaosParamBinaryData m_chaosParams;
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

            qint8 hasChaosParam = r->ReadByte("hasChaosParams");
            if (hasChaosParam != 0)
            {
                entry.m_chaosParams.m_chaosLevel = r->ReadByte("m_chaosLevel");
                entry.m_chaosParams.m_chaosCollectorParamId = r->ReadInt("m_chaosCollectorParamId");
            }

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif