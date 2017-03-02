#ifndef ITEMSET_H
#define ITEMSET_H

#include "BaseBinaryReader.h"

struct ItemSetBinaryData
{
    qint16 m_id;
    qint32 m_linkedItemReferenceId;
    QList<qint32> m_itemsId;
    QMap<qint32, QList<qint32>> m_effectIdsByPartCount;
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
                qint32 effectIdsByPartCountKey = r->ReadInt();
                QList<qint32> effectIdsByPartCountValue = r->ReadIntArray();

                entry.m_effectIdsByPartCount.insert(effectIdsByPartCountKey, effectIdsByPartCountValue);
            }

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif
