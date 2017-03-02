#include "BaseBinaryReader.h"

struct HealthPenalty
{
    qint8 m_penaltyType;
    qint8 m_value;
};

struct HealthItem
{
    qint32 m_itemId;
    qint32 m_value;
};

struct MealItem
{
    qint32 m_itemId;
    bool m_visible;
};

struct SleepItem
{
    qint32 m_itemId;
    qint64 m_duration;
};

struct ColorItem
{
    qint32 m_itemId;
    qint32 m_partId;
    qint32 m_colorABGR;
};

struct ReskinItem
{
    qint32 m_itemId;
    qint32 m_gfxId;
};

struct PetBinaryData
{
    qint32 m_id;
    qint32 m_itemRefId;
    qint32 m_gfxId;
    qint32 m_itemColorRefId;
    qint32 m_itemReskinRefId;
    qint32 m_health;
    qint64 m_minMealInterval;
    qint64 m_maxMealInterval;
    qint8 m_xpByMeal;
    qint16 m_xpPerLevel;
    qint16 m_levelMax;
    qint8 m_mountType;
    QList<HealthPenalty> m_healthPenalties;
    QList<HealthItem> m_healthItems;
    QList<MealItem> m_mealItems;
    QList<SleepItem> m_sleepItems;
    QList<qint32> m_equipmentItems;
    QList<ColorItem> m_colorItems;
    QList<ReskinItem> m_reskinItems;
};

class Pet : public BaseBinaryReader
{
public:
    Pet() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            PetBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_itemRefId = r->ReadInt("m_itemRefId");
            entry.m_gfxId = r->ReadInt("m_gfxId");
            entry.m_itemColorRefId = r->ReadInt("m_itemColorRefId");
            entry.m_itemReskinRefId = r->ReadInt("m_itemReskinRefId");
            entry.m_health = r->ReadInt("m_health");
            entry.m_minMealInterval = r->ReadLong("m_minMealInterval");
            entry.m_maxMealInterval = r->ReadLong("m_maxMealInterval");
            entry.m_xpByMeal = r->ReadByte("m_xpByMeal");
            entry.m_xpPerLevel = r->ReadShort("m_xpPerLevel");
            entry.m_levelMax = r->ReadShort("m_levelMax");
            entry.m_mountType = r->ReadByte("m_mountType");

            qint32 healthPenaltieCount = r->ReadInt();

            for (qint32 i = 0; i < healthPenaltieCount; ++i)
            {
                HealthPenalty healthPenalty;

                healthPenalty.m_penaltyType = r->ReadByte();
                healthPenalty.m_value = r->ReadByte();

                entry.m_healthPenalties.push_back(healthPenalty);
            }


            qint32 healthItemCount = r->ReadInt();

            for (qint32 i = 0; i < healthItemCount; ++i)
            {
                HealthItem healthItem;

                healthItem.m_itemId = r->ReadInt();
                healthItem.m_value = r->ReadInt();

                entry.m_healthItems.push_back(healthItem);
            }


            qint32 mealItemCount = r->ReadInt();

            for (qint32 i = 0; i < mealItemCount; ++i)
            {
                MealItem mealItem;

                mealItem.m_itemId = r->ReadInt();
                mealItem.m_visible = r->ReadBool();

                entry.m_mealItems.push_back(mealItem);
            }


            qint32 sleepItemCount = r->ReadInt();

            for (qint32 i = 0; i < sleepItemCount; ++i)
            {
                SleepItem sleepItem;

                sleepItem.m_itemId = r->ReadInt();
                sleepItem.m_duration = r->ReadLong();

                entry.m_sleepItems.push_back(sleepItem);
            }

            entry.m_equipmentItems = r->ReadIntArray("m_equipmentItems");

            qint32 colorItemCount = r->ReadInt();

            for (qint32 i = 0; i < colorItemCount; ++i)
            {
                ColorItem colorItem;

                colorItem.m_itemId = r->ReadInt();
                colorItem.m_partId = r->ReadInt();
                colorItem.m_colorABGR = r->ReadInt();

                entry.m_colorItems.push_back(colorItem);
            }


            qint32 reskinItemCount = r->ReadInt();

            for (qint32 i = 0; i < reskinItemCount; ++i)
            {
                ReskinItem reskinItem;

                reskinItem.m_itemId = r->ReadInt();
                reskinItem.m_gfxId = r->ReadInt();

                entry.m_reskinItems.push_back(reskinItem);
            }


            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};