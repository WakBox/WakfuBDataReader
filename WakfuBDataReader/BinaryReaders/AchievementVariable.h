#ifndef ACHIEVEMENTVARIABLE_H
#define ACHIEVEMENTVARIABLE_H

#include "BaseBinaryReader.h"

struct AchievementVariableBinaryData
{
    qint32 m_id;
    QString m_name;
    bool m_exportForSteam;
};

class AchievementVariable : public BaseBinaryReader
{
public:
    AchievementVariable() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            AchievementVariableBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_name = r->ReadString("m_name");
            entry.m_exportForSteam = r->ReadBool("m_exportForSteam");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif