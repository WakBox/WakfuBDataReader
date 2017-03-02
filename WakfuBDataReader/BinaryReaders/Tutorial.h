#include "BaseBinaryReader.h"

struct Event
{
    qint32 m_eventId;
};

struct TutorialBinaryData
{
    qint32 m_id;
    QList<Event> m_eventIds;
};

class Tutorial : public BaseBinaryReader
{
public:
    Tutorial() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            TutorialBinaryData entry;

            entry.m_id = r->ReadInt("m_id");

            qint32 eventIdCount = r->ReadInt();

            for (qint32 i = 0; i < eventIdCount; ++i)
            {
                Event event;

                event.m_eventId = r->ReadInt();

                entry.m_eventIds.push_back(event);
            }


            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};