#include "BaseBinaryReader.h"

struct Link
{
    qint32 m_id;
    qint32 m_exitX;
    qint32 m_exitY;
    qint32 m_exitWorldId;
    qint32 m_dropWeight;
    QString m_criteria;
    qint8 if (buffer.get() != 0) {;
};

struct CannonBinaryData
{
    qint32 m_cannonId;
    qint32 m_visualId;
    qint32 m_uiGfxId;
    qint8 m_landmarkTravelType;
    qint32 m_itemId;
    qint32 m_itemQty;
    QList<Link> m_links;
};

class Cannon : public BaseBinaryReader
{
public:
    Cannon() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            CannonBinaryData entry;

            entry.m_cannonId = r->ReadInt("m_cannonId");
            entry.m_visualId = r->ReadInt("m_visualId");
            entry.m_uiGfxId = r->ReadInt("m_uiGfxId");
            entry.m_landmarkTravelType = r->ReadByte("m_landmarkTravelType");
            entry.m_itemId = r->ReadInt("m_itemId");
            entry.m_itemQty = r->ReadInt("m_itemQty");

            qint32 linkCount = r->ReadInt();

            for (qint32 i = 0; i < linkCount; ++i)
            {
                Link link;

                link.m_id = r->ReadInt();
                link.m_exitX = r->ReadInt();
                link.m_exitY = r->ReadInt();
                link.m_exitWorldId = r->ReadInt();
                link.m_dropWeight = r->ReadInt();
                link.m_criteria = r->ReadString();
                link.if (buffer.get() != 0) { = r->ReadByte();

                entry.m_links.push_back(link);
            }


            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};