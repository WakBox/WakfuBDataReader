#ifndef INTERACTIVEELEMENTTEMPLATE_H
#define INTERACTIVEELEMENTTEMPLATE_H

#include "BaseBinaryReader.h"

struct Point3
{
    qint32 m_x;
    qint32 m_y;
    qint16 m_z;
};

struct InteractiveElementTemplateBinaryData
{
    qint32 m_id;
    qint16 m_modelType;
    qint16 m_worldId;
    qint32 m_x;
    qint32 m_y;
    qint16 m_z;
    qint16 m_initialState;
    bool m_initiallyVisible;
    bool m_initiallyUsable;
    bool m_blockingMovement;
    bool m_blockingLos;
    qint8 m_direction;
    qint16 m_activationPattern;
    QString m_parameter;
    qint32 m_templateId;
    QList<qint32> m_properties;
    QList<Point3> m_positionsTrigger;
    QMap<qint16, qint32> m_actions;
    QList<qint32> m_views;
};

class InteractiveElementTemplate : public BaseBinaryReader
{
public:
    InteractiveElementTemplate() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            InteractiveElementTemplateBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_modelType = r->ReadShort("m_modelType");
            entry.m_worldId = r->ReadShort("m_worldId");
            entry.m_x = r->ReadInt("m_x");
            entry.m_y = r->ReadInt("m_y");
            entry.m_z = r->ReadShort("m_z");
            entry.m_initialState = r->ReadShort("m_initialState");
            entry.m_initiallyVisible = r->ReadBool("m_initiallyVisible");
            entry.m_initiallyUsable = r->ReadBool("m_initiallyUsable");
            entry.m_blockingMovement = r->ReadBool("m_blockingMovement");
            entry.m_blockingLos = r->ReadBool("m_blockingLos");
            entry.m_direction = r->ReadByte("m_direction");
            entry.m_activationPattern = r->ReadShort("m_activationPattern");
            entry.m_parameter = r->ReadString("m_parameter");
            entry.m_templateId = r->ReadInt("m_templateId");
            entry.m_properties = r->ReadIntArray("m_properties");

            qint32 positionsTriggerCount = r->ReadInt();

            for (qint32 i = 0; i < positionsTriggerCount; ++i)
            {
                Point3 point3;

                point3.m_x = r->ReadInt();
                point3.m_y = r->ReadInt();
                point3.m_z = r->ReadShort();

                entry.m_positionsTrigger.push_back(point3);
            }

            qint32 actionCount = r->ReadInt();

            for (qint32 i = 0; i < actionCount; ++i)
            {
                qint16 actionKey = r->ReadShort();
                qint32 actionValue = r->ReadInt();

                entry.m_actions.insert(actionKey, actionValue);
            }

            entry.m_views = r->ReadIntArray("m_views");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif