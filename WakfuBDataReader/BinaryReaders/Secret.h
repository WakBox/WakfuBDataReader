#ifndef SECRET_H
#define SECRET_H

#include "BaseBinaryReader.h"

struct SecretBinaryData
{
    qint32 m_id;
    qint16 m_level;
    qint16 m_itemId;
};

class Secret : public BaseBinaryReader
{
public:
    Secret() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            SecretBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_level = r->ReadShort("m_level");
            entry.m_itemId = r->ReadShort("m_itemId");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif