#include "BaseBinaryReader.h"

struct CharacGainPerLevelBinaryData
{
    qint16 m_breedId;
    QMap<qint8, float> m_gains;
};

class CharacGainPerLevel : public BaseBinaryReader
{
public:
    CharacGainPerLevel() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            CharacGainPerLevelBinaryData entry;

            entry.m_breedId = r->ReadShort("m_breedId");

            qint32 gainCount = r->ReadInt();

            for (qint32 i = 0; i < gainCount; ++i)
            {
                qint8 key = r->ReadByte();
                float value = r->ReadFloat();

                entry.m_gains.insert(key, value);
            }

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};
