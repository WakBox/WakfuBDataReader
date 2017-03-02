#ifndef ACHIEVEMENTLIST_H
#define ACHIEVEMENTLIST_H

#include "BaseBinaryReader.h"

struct AchievementListData
{
    qint32 m_achievementId;
    qint32 m_order;
};

struct AchievementListBinaryData
{
    qint32 m_id;
    QList<AchievementListData> m_elements;
};

class AchievementList : public BaseBinaryReader
{
public:
    AchievementList() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            AchievementListBinaryData entry;

            entry.m_id = r->ReadInt("m_id");

            qint32 elementCount = r->ReadInt();

            for (qint32 i = 0; i < elementCount; ++i)
            {
                AchievementListData achievementListData;

                achievementListData.m_achievementId = r->ReadInt();
                achievementListData.m_order = r->ReadInt();

                entry.m_elements.push_back(achievementListData);
            }


            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif