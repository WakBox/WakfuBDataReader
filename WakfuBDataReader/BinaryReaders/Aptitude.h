#ifndef APTITUDE_H
#define APTITUDE_H

#include "BaseBinaryReader.h"

struct AptitudeBinaryData
{
    qint32 m_id;
    qint16 m_breedId;
    qint8 m_characteristicId;
    qint32 m_uiId;
    qint32 m_aptitudeGfxId;
    qint32 m_spellGfxId;
    qint16 m_maxLevel;
    qint32 m_constantCost;
    QList<qint32> m_variableCost;
    qint32 m_linkedSpellId;
    QList<qint32> m_levelUnlock;
    QList<qint32> m_effectIds;
};

class Aptitude : public BaseBinaryReader
{
public:
    Aptitude() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            AptitudeBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_breedId = r->ReadShort("m_breedId");
            entry.m_characteristicId = r->ReadByte("m_characteristicId");
            entry.m_uiId = r->ReadInt("m_uiId");
            entry.m_aptitudeGfxId = r->ReadInt("m_aptitudeGfxId");
            entry.m_spellGfxId = r->ReadInt("m_spellGfxId");
            entry.m_maxLevel = r->ReadShort("m_maxLevel");
            entry.m_constantCost = r->ReadInt("m_constantCost");
            entry.m_variableCost = r->ReadIntArray("m_variableCost");
            entry.m_linkedSpellId = r->ReadInt("m_linkedSpellId");
            entry.m_levelUnlock = r->ReadIntArray("m_levelUnlock");
            entry.m_effectIds = r->ReadIntArray("m_effectIds");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif