#include "BaseBinaryReader.h"

struct Interactive
{
    qint32 m_uid;
    qint32 m_templateId;
    qint8 m_x;
    qint8 m_y;
    qint8 m_z;
};

struct Skin
{
    qint32 m_itemId;
    qint32 m_editorGroupId;
};

struct WorldEffect
{
    qint32 m_buffId;
};

struct HavenWorldBuildingBinaryData
{
    qint32 m_id;
    qint16 m_catalogEntryId;
    qint32 m_kamaCost;
    qint32 m_ressourceCost;
    qint8 m_workersGranted;
    qint8 m_workers;
    qint32 m_editorGroupId;
    bool m_canBeDestroyed;
    QList<Interactive> m_interactives;
    QList<Skin> m_skins;
    QList<qint32> m_effectIds;
    QList<WorldEffect> m_worldEffects;
};

class HavenWorldBuilding : public BaseBinaryReader
{
public:
    HavenWorldBuilding() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            HavenWorldBuildingBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_catalogEntryId = r->ReadShort("m_catalogEntryId");
            entry.m_kamaCost = r->ReadInt("m_kamaCost");
            entry.m_ressourceCost = r->ReadInt("m_ressourceCost");
            entry.m_workersGranted = r->ReadByte("m_workersGranted");
            entry.m_workers = r->ReadByte("m_workers");
            entry.m_editorGroupId = r->ReadInt("m_editorGroupId");
            entry.m_canBeDestroyed = r->ReadBool("m_canBeDestroyed");

            qint32 interactiveCount = r->ReadInt();

            for (qint32 i = 0; i < interactiveCount; ++i)
            {
                Interactive interactive;

                interactive.m_uid = r->ReadInt();
                interactive.m_templateId = r->ReadInt();
                interactive.m_x = r->ReadByte();
                interactive.m_y = r->ReadByte();
                interactive.m_z = r->ReadByte();

                entry.m_interactives.push_back(interactive);
            }


            qint32 skinCount = r->ReadInt();

            for (qint32 i = 0; i < skinCount; ++i)
            {
                Skin skin;

                skin.m_itemId = r->ReadInt();
                skin.m_editorGroupId = r->ReadInt();

                entry.m_skins.push_back(skin);
            }

            entry.m_effectIds = r->ReadIntArray("m_effectIds");

            qint32 worldEffectCount = r->ReadInt();

            for (qint32 i = 0; i < worldEffectCount; ++i)
            {
                WorldEffect worldEffect;

                worldEffect.m_buffId = r->ReadInt();

                entry.m_worldEffects.push_back(worldEffect);
            }


            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};