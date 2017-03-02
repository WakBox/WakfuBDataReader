#ifndef BOARDINTERACTIVEELEMENTPARAM_H
#define BOARDINTERACTIVEELEMENTPARAM_H

#include "BaseBinaryReader.h"

struct BoardInteractiveElementParamBinaryData
{
    qint32 m_id;
};

class BoardInteractiveElementParam : public BaseBinaryReader
{
public:
    BoardInteractiveElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            BoardInteractiveElementParamBinaryData entry;

            entry.m_id = r->ReadInt("m_id");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif