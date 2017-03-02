#include "BaseBinaryReader.h"

struct MagiCraftLootEntry
{
    qint32 m_itemId;
};

struct MagiCraftLootListBinaryData
{
    qint32 m_id;
    qint8 m_gemType;
    QList<MagiCraftLootEntry> m_entries;
};

class MagiCraftLootList : public BaseBinaryReader
{
public:
    MagiCraftLootList() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            MagiCraftLootListBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_gemType = r->ReadByte("m_gemType");

            qint32 entrieCount = r->ReadInt();

            for (qint32 i = 0; i < entrieCount; ++i)
            {
                MagiCraftLootEntry lootEntry;

                lootEntry.m_itemId = r->ReadInt();

                entry.m_entries.push_back(lootEntry);
            }


            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};
