#ifndef BOOKCASEINTERACTIVEELEMENTPARAM_H
#define BOOKCASEINTERACTIVEELEMENTPARAM_H

#include "BaseBinaryReader.h"

struct BookcaseInteractiveElementParamBinaryData
{
    qint32 m_id;
    qint8 m_size;
};

class BookcaseInteractiveElementParam : public BaseBinaryReader
{
public:
    BookcaseInteractiveElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            BookcaseInteractiveElementParamBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_size = r->ReadByte("m_size");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif