#ifndef DESTRUCTIBLEELEMENTPARAM_H
#define DESTRUCTIBLEELEMENTPARAM_H

#include "BaseBinaryReader.h"

struct DestructibleElementParamBinaryData
{
    qint32 m_id;
    qint32 m_pdv;
    qint32 m_regenDelay;
    qint32 m_resWater;
    qint32 m_resFire;
    qint32 m_resEarth;
    qint32 m_resWind;
    QList<qint32> m_effectIds;
};

class DestructibleElementParam : public BaseBinaryReader
{
public:
    DestructibleElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            DestructibleElementParamBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_pdv = r->ReadInt("m_pdv");
            entry.m_regenDelay = r->ReadInt("m_regenDelay");
            entry.m_resWater = r->ReadInt("m_resWater");
            entry.m_resFire = r->ReadInt("m_resFire");
            entry.m_resEarth = r->ReadInt("m_resEarth");
            entry.m_resWind = r->ReadInt("m_resWind");
            entry.m_effectIds = r->ReadIntArray("m_effectIds");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif