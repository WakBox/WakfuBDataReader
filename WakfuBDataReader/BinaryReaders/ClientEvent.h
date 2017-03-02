#ifndef CLIENTEVENT_H
#define CLIENTEVENT_H

#include "BaseBinaryReader.h"

struct EventAction
{
    qint32 m_id;
    qint32 m_type;
    QList<QString> m_params;
};

struct EventActionGroup
{
    qint32 m_id;
    qint16 m_dropRate;
    QString m_criterion;
    QList<EventAction> m_actions;
};

struct ClientEventBinaryData
{
    qint32 m_id;
    qint32 m_type;
    qint16 m_dropRate;
    qint16 m_maxCount;
    QString m_criterion;
    QList<QString> m_filters;
    bool m_activeOnStart;
    QList<EventActionGroup> m_actionGroups;
};

class ClientEvent : public BaseBinaryReader
{
public:
    ClientEvent() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            ClientEventBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_type = r->ReadInt("m_type");
            entry.m_dropRate = r->ReadShort("m_dropRate");
            entry.m_maxCount = r->ReadShort("m_maxCount");
            entry.m_criterion = r->ReadString("m_criterion");
            entry.m_filters = r->ReadStringArray("m_filters");
            entry.m_activeOnStart = r->ReadBool("m_activeOnStart");

            qint32 actionGroupCount = r->ReadInt();

            for (qint32 i = 0; i < actionGroupCount; ++i)
            {
                EventActionGroup eventActionGroup;

                eventActionGroup.m_id = r->ReadInt();
                eventActionGroup.m_dropRate = r->ReadShort();
                eventActionGroup.m_criterion = r->ReadString();
                qint32 actionCount = r->ReadInt();

                for (qint32 j = 0; j < actionCount; ++j)
                {
                    EventAction eventAction;

                    eventAction.m_id = r->ReadInt();
                    eventAction.m_type = r->ReadInt();
                    eventAction.m_params = r->ReadStringArray();

                    eventActionGroup.m_actions.push_back(eventAction);
                }

                entry.m_actionGroups.push_back(eventActionGroup);
            }


            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif