#ifndef CRAFT_H
#define CRAFT_H

#include "BaseBinaryReader.h"

struct CraftBinaryData
{
    qint32 m_craftId;
    qint32 m_bookItemId;
    float m_xpFactor;
    bool m_innate;
    bool m_conceptualCraft;
    bool m_hiddenCraft;
};

class Craft : public BaseBinaryReader
{
public:
    Craft() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            CraftBinaryData entry;

            entry.m_craftId = r->ReadInt("m_craftId");
            entry.m_bookItemId = r->ReadInt("m_bookItemId");
            entry.m_xpFactor = r->ReadFloat("m_xpFactor");
            entry.m_innate = r->ReadBool("m_innate");
            entry.m_conceptualCraft = r->ReadBool("m_conceptualCraft");
            entry.m_hiddenCraft = r->ReadBool("m_hiddenCraft");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif