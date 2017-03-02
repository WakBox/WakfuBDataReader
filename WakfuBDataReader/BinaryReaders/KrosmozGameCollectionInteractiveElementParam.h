#ifndef KROSMOZGAMECOLLECTIONINTERACTIVEELEMENTPARAM_H
#define KROSMOZGAMECOLLECTIONINTERACTIVEELEMENTPARAM_H

#include "BaseBinaryReader.h"

struct KrosmozGameCollectionInteractiveElementParamBinaryData
{
    qint32 m_id;
    qint8 m_gameId;
};

class KrosmozGameCollectionInteractiveElementParam : public BaseBinaryReader
{
public:
    KrosmozGameCollectionInteractiveElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            KrosmozGameCollectionInteractiveElementParamBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_gameId = r->ReadByte("m_gameId");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif