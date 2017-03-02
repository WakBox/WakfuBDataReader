#include "BaseBinaryReader.h"

struct GroundBinaryData
{
    qint32 m_id;
    QMap<qint32, short> m_resourceFertility;
    QMap<qint16, qint16> m_resourceTypeFertility;
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
                qint32 resourceFertilityKey = r->ReadInt();
                qint16 resourceFertilityValue = r->ReadShort();

                entry.m_resourceFertility.insert(resourceFertilityKey, resourceFertilityValue);
            }

            qint32 resourceFertilityKey = r->ReadInt();

            for (qint32 i = 0; i < resourceFertilityKey; ++i)
            {
                qint16 resourceTypeFertilityKey = r->ReadShort();
                qint16 resourceTypeFertilityValue = r->ReadShort();

                entry.m_resourceTypeFertility.insert(resourceTypeFertilityKey, resourceTypeFertilityValue);
            }

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};
