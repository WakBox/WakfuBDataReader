#ifndef ARCADECHALLENGE_H
#define ARCADECHALLENGE_H

#include "BaseBinaryReader.h"

struct ArcadeChallengeBinaryData
{
    qint32 m_id;
};

class ArcadeChallenge : public BaseBinaryReader
{
public:
    ArcadeChallenge() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            ArcadeChallengeBinaryData entry;

            entry.m_id = r->ReadInt("m_id");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif