#ifndef HAVENWORLDBUILDINGVISUALDEFINITION_H
#define HAVENWORLDBUILDINGVISUALDEFINITION_H

#include "BaseBinaryReader.h"

struct VisualElement
{
    qint32 m_uid;
    qint32 m_gfxId;
    bool m_hasGuildColor;
    bool m_occluder;
    qint8 m_height;
    QString m_animName;
    qint8 m_direction;
    qint8 m_x;
    qint8 m_y;
    qint8 m_z;
};

struct HavenWorldBuildingVisualDefinitionBinaryData
{
    qint32 m_id;
    qint32 m_buildingId;
    QList<VisualElement> m_elements;
};

class HavenWorldBuildingVisualDefinition : public BaseBinaryReader
{
public:
    HavenWorldBuildingVisualDefinition() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            HavenWorldBuildingVisualDefinitionBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_buildingId = r->ReadInt("m_buildingId");

            qint32 elementCount = r->ReadInt();

            for (qint32 i = 0; i < elementCount; ++i)
            {
                VisualElement visualElement;

                visualElement.m_uid = r->ReadInt();
                visualElement.m_gfxId = r->ReadInt();
                visualElement.m_hasGuildColor = r->ReadBool();
                visualElement.m_occluder = r->ReadBool();
                visualElement.m_height = r->ReadByte();
                visualElement.m_animName = r->ReadString();
                visualElement.m_direction = r->ReadByte();
                visualElement.m_x = r->ReadByte();
                visualElement.m_y = r->ReadByte();
                visualElement.m_z = r->ReadByte();

                entry.m_elements.push_back(visualElement);
            }


            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif