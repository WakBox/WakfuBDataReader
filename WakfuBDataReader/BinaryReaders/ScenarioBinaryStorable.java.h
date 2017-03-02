#ifndef SCENARIOBINARYSTORABLE.JAVA_H
#define SCENARIOBINARYSTORABLE.JAVA_H

#include "BaseBinaryReader.h"

struct 
{
};

class ScenarioBinaryStorable.java : public BaseBinaryReader
{
public:
    ScenarioBinaryStorable.java() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

             entry;


            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif