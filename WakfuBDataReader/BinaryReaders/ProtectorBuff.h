#ifndef PROTECTORBUFF_H
#define PROTECTORBUFF_H

#include "BaseBinaryReader.h"

struct ProtectorBuffBinaryData
{
    qint32 m_buffId;
    qint32 m_gfxId;
    QString m_criteria;
    qint8 m_origin;
    QList<qint32> m_effects;
};

class ProtectorBuff : public BaseBinaryReader
{
public:
    ProtectorBuff() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            ProtectorBuffBinaryData entry;

            entry.m_buffId = r->ReadInt("m_buffId");
            entry.m_gfxId = r->ReadInt("m_gfxId");
            entry.m_criteria = r->ReadString("m_criteria");
            entry.m_origin = r->ReadByte("m_origin");
            entry.m_effects = r->ReadIntArray("m_effects");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif