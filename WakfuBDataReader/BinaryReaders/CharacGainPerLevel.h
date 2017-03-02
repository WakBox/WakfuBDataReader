#include "BaseBinaryReader.h"

struct CharacGainPerLevelBinaryData
{
    qint16 m_breedId;
    QList<TByteFloatHashMap(gainCount);> m_gains;
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
                TByteFloatHashMap(gainCount); tByteFloatHashMap(gainCount);;


                entry.m_gains.push_back(tByteFloatHashMap(gainCount););
            }


            qint32 gainKey = r->ReadByte();

            for (qint32 i = 0; i < gainKey; ++i)
            {
                ReadFloat(); readFloat();;


                entry.gainValue.push_back(readFloat(););
            }


            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};