#include "BaseBinaryReader.h"

struct ChallengeLootEntry
{
    qint32 m_challengeId;
    QString m_criteria;
};

struct ChallengeLootListBinaryData
{
    qint32 m_id;
    QList<ChallengeLootEntry> m_entries;
};

class ChallengeLootList : public BaseBinaryReader
{
public:
    ChallengeLootList() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            ChallengeLootListBinaryData entry;

            entry.m_id = r->ReadInt("m_id");

            qint32 entrieCount = r->ReadInt();

            for (qint32 i = 0; i < entrieCount; ++i)
            {
                ChallengeLootEntry challengeLootEntry;

                challengeLootEntry.m_challengeId = r->ReadInt();
                challengeLootEntry.m_criteria = r->ReadString();

                entry.m_entries.push_back(challengeLootEntry);
            }


            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};