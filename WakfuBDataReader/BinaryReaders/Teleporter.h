#include "BaseBinaryReader.h"

struct Destination
{
    qint32 m_destinationId;
    qint32 m_x;
    qint32 m_y;
    qint32 m_z;
    qint32 m_worldId;
    qint8 m_direction;
    QString m_criteria;
    qint32 m_visualId;
    qint32 m_apsId;
    qint16 m_delay;
    qint32 m_itemConsumed;
    qint16 m_itemQuantity;
    qint16 m_kamaCost;
    bool m_doConsumeItem;
    bool m_isInvisible;
    QString m_loadingAnimationName;
    qint32 m_loadingMinDuration;
    qint32 m_loadingFadeInDuration;
    qint32 m_loadingFadeOutDuration;
};

struct TeleporterBinaryData
{
    qint32 m_teleporterId;
    qint32 m_lockId;
    QList<Destination> m_destinations;
};

class Teleporter : public BaseBinaryReader
{
public:
    Teleporter() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            TeleporterBinaryData entry;

            entry.m_teleporterId = r->ReadInt("m_teleporterId");
            entry.m_lockId = r->ReadInt("m_lockId");

            qint32 destinationCount = r->ReadInt();

            for (qint32 i = 0; i < destinationCount; ++i)
            {
                Destination destination;

                destination.m_destinationId = r->ReadInt();
                destination.m_x = r->ReadInt();
                destination.m_y = r->ReadInt();
                destination.m_z = r->ReadInt();
                destination.m_worldId = r->ReadInt();
                destination.m_direction = r->ReadByte();
                destination.m_criteria = r->ReadString();
                destination.m_visualId = r->ReadInt();
                destination.m_apsId = r->ReadInt();
                destination.m_delay = r->ReadShort();
                destination.m_itemConsumed = r->ReadInt();
                destination.m_itemQuantity = r->ReadShort();
                destination.m_kamaCost = r->ReadShort();
                destination.m_doConsumeItem = r->ReadBool();
                destination.m_isInvisible = r->ReadBool();
                destination.m_loadingAnimationName = r->ReadString();
                destination.m_loadingMinDuration = r->ReadInt();
                destination.m_loadingFadeInDuration = r->ReadInt();
                destination.m_loadingFadeOutDuration = r->ReadInt();

                entry.m_destinations.push_back(destination);
            }


            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};