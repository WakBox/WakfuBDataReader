#include "BaseBinaryReader.h"

struct TreasureBinaryData
{
    qint32 m_id;
    qint32 m_usedItem;
    qint32 m_rewardItem;
    qint16 m_quantity;
    qint32 m_rewardKama;
    qint32 m_rewardLootChest;
    qint32 m_duration;
    QString m_criterion;
    float m_winPercent;
};

class Treasure : public BaseBinaryReader
{
public:
    Treasure() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            TreasureBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_usedItem = r->ReadInt("m_usedItem");
            entry.m_rewardItem = r->ReadInt("m_rewardItem");
            entry.m_quantity = r->ReadShort("m_quantity");
            entry.m_rewardKama = r->ReadInt("m_rewardKama");
            entry.m_rewardLootChest = r->ReadInt("m_rewardLootChest");
            entry.m_duration = r->ReadInt("m_duration");
            entry.m_criterion = r->ReadString("m_criterion");
            entry.m_winPercent = r->ReadFloat("m_winPercent");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};