#include "BaseBinaryReader.h"

struct GroundBinaryData
{
    qint32 m_id;
    QList<TIntShortHashMap(resourceFertilityCount);> m_resourceFertility;
    QList<TShortShortHashMap(resourceTypeFertilityCount);> m_resourceTypeFertility;
};

class Ground : public BaseBinaryReader
{
public:
    Ground() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            GroundBinaryData entry;

            entry.m_id = r->ReadInt("m_id");

            qint32 resourceFertilityCount = r->ReadInt();

            for (qint32 i = 0; i < resourceFertilityCount; ++i)
            {
                TIntShortHashMap(resourceFertilityCount); tIntShortHashMap(resourceFertilityCount);;


                entry.m_resourceFertility.push_back(tIntShortHashMap(resourceFertilityCount););
            }


            qint32 resourceFertilityKey = r->ReadInt();

            for (qint32 i = 0; i < resourceFertilityKey; ++i)
            {
                ReadShort(); readShort();;


                entry.resourceFertilityValue.push_back(readShort(););
            }


            qint32 resourceTypeFertilityCount = r->ReadInt();

            for (qint32 i = 0; i < resourceTypeFertilityCount; ++i)
            {
                TShortShortHashMap(resourceTypeFertilityCount); tShortShortHashMap(resourceTypeFertilityCount);;


                entry.m_resourceTypeFertility.push_back(tShortShortHashMap(resourceTypeFertilityCount););
            }


            qint32 resourceTypeFertilityKey = r->ReadShort();

            for (qint32 i = 0; i < resourceTypeFertilityKey; ++i)
            {
                ReadShort(); readShort();;


                entry.resourceTypeFertilityValue.push_back(readShort(););
            }


            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};