#ifndef HAVENWORLDBUILDINGCATALOG_H
#define HAVENWORLDBUILDINGCATALOG_H

#include "BaseBinaryReader.h"

struct BuildingCondition
{
    qint32 m_buildingTypeNeeded;
    qint32 m_quantity;
};

struct HavenWorldBuildingCatalogBinaryData
{
    qint32 m_id;
    qint32 m_order;
    qint32 m_buildingType;
    qint32 m_categoryId;
    bool m_buyable;
    qint16 m_maxQuantity;
    bool m_isDecoOnly;
    qint32 m_buildingSoundId;
    QList<BuildingCondition> m_buildingCondition;
};

class HavenWorldBuildingCatalog : public BaseBinaryReader
{
public:
    HavenWorldBuildingCatalog() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            HavenWorldBuildingCatalogBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_order = r->ReadInt("m_order");
            entry.m_buildingType = r->ReadInt("m_buildingType");
            entry.m_categoryId = r->ReadInt("m_categoryId");
            entry.m_buyable = r->ReadBool("m_buyable");
            entry.m_maxQuantity = r->ReadShort("m_maxQuantity");
            entry.m_isDecoOnly = r->ReadBool("m_isDecoOnly");
            entry.m_buildingSoundId = r->ReadInt("m_buildingSoundId");

            qint32 buildingConditionCount = r->ReadInt();

            for (qint32 i = 0; i < buildingConditionCount; ++i)
            {
                BuildingCondition buildingCondition;

                buildingCondition.m_buildingTypeNeeded = r->ReadInt();
                buildingCondition.m_quantity = r->ReadInt();

                entry.m_buildingCondition.push_back(buildingCondition);
            }


            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif