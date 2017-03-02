#ifndef BAGS_H
#define BAGS_H

#include "BaseBinaryReader.h"

struct BagsBinaryData
{
    qint32 m_id;
    qint16 m_capacity;
    qint32 m_bagType;
    QList<qint32> m_validItemCategories;
};

class Bags : public BaseBinaryReader
{
public:
    Bags() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            BagsBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_capacity = r->ReadShort("m_capacity");
            entry.m_bagType = r->ReadInt("m_bagType");
            entry.m_validItemCategories = r->ReadIntArray("m_validItemCategories");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif