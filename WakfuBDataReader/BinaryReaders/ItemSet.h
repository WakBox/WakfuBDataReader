#include "BaseBinaryReader.h"

struct ItemSetBinaryData
{
    qint16 m_id;
    qint32 m_linkedItemReferenceId;
    QList<qint32> m_itemsId;
    QList<TIntObjectHashMap<int> m_effectIdsByPartCount;
};

class ItemSet : public BaseBinaryReader
{
public:
    ItemSet() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            ItemSetBinaryData entry;

            entry.m_id = r->ReadShort("m_id");
            entry.m_linkedItemReferenceId = r->ReadInt("m_linkedItemReferenceId");
            entry.m_itemsId = r->ReadIntArray("m_itemsId");

            qint32 effectIdsByPartCountCount = r->ReadInt();

            for (qint32 i = 0; i < effectIdsByPartCountCount; ++i)
            {
                TIntObjectHashMap<int tIntObjectHashMap<int;


                entry.m_effectIdsByPartCount.push_back(tIntObjectHashMap<int);
            }


            qint32 effectIdsByPartCountKey = r->ReadInt();

            for (qint32 i = 0; i < effectIdsByPartCountKey; ++i)
            {
                ReadIntArray(); readIntArray();;


                entry.effectIdsByPartCountValue.push_back(readIntArray(););
            }


            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};