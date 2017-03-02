#ifndef ACHIEVEMENTCATEGORY_H
#define ACHIEVEMENTCATEGORY_H

#include "BaseBinaryReader.h"

struct AchievementCategoryBinaryData
{
    qint32 m_id;
    qint32 m_parentId;
};

class AchievementCategory : public BaseBinaryReader
{
public:
    AchievementCategory() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            AchievementCategoryBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_parentId = r->ReadInt("m_parentId");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif