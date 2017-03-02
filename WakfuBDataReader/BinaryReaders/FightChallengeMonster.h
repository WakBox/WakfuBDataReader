#include "BaseBinaryReader.h"

struct FightChallengeMonsterBinaryData
{
    qint32 m_id;
    qint16 m_randomRolls;
    qint16 m_forcedRolls;
    QList<qint32> m_forcedChallenges;
};

class FightChallengeMonster : public BaseBinaryReader
{
public:
    FightChallengeMonster() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            FightChallengeMonsterBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_randomRolls = r->ReadShort("m_randomRolls");
            entry.m_forcedRolls = r->ReadShort("m_forcedRolls");
            entry.m_forcedChallenges = r->ReadIntArray("m_forcedChallenges");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};