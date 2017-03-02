#include "BaseBinaryReader.h"

struct LootEntry
{
    qint32 m_itemId;
    qint16 m_quantity;
    qint16 m_quantityPerItem;
};

struct LightLootListBinaryData
{
    qint32 m_id;
    QList<LootEntry> m_entries;
};

class LightLootList : public BaseBinaryReader
{
public:
    LightLootList() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            LightLootListBinaryData entry;

            entry.m_id = r->ReadInt("m_id");

            qint32 entrieCount = r->ReadInt();

            for (qint32 i = 0; i < entrieCount; ++i)
            {
                LootEntry lootEntry;

                lootEntry.m_itemId = r->ReadInt();
                lootEntry.m_quantity = r->ReadShort();
                lootEntry.m_quantityPerItem = r->ReadShort();

                entry.m_entries.push_back(lootEntry);
            }


            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};