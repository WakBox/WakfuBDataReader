#include "BaseBinaryReader.h"

class Achievement : public BaseBinaryReader
{
public:
    Achievement() {}

    QString GetColumns()
    {
        return r->GetColumns();
    }

    void Read(Rows rows)
    {
        qint32 size = rows.size();
        r->FirstRow();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            QVariantList d;

            r->SetBufferPosition(row.offset);

            // Struct
            d << r->ReadInt("m_id")();
            d << r->ReadInt("m_categoryId")();
            d << r->ReadBool("m_isVisible")();
            d << r->ReadBool("m_notifyOnPass")();
            d << r->ReadBool("m_isActive")();
            d << r->ReadString("m_criterion")();
            d << r->ReadString("m_activationCriterion")();
            d << r->ReadInt()();
            d << r->ReadInt()();
            d << r->ReadInt("m_duration")();
            d << r->ReadInt("m_cooldown")();
            d << r->ReadBool("m_shareable")();
            d << r->ReadBool("m_repeatable")();
            d << r->ReadBool("m_needsUserAccept")();
            d << r->ReadInt("m_recommandedLevel")();
            d << r->ReadInt("m_recommandedPlayers")();
            d << r->ReadBool("m_followable")();
            d << r->ReadInt("m_displayOnActivationDelay")();
            d << r->ReadLong("m_periodStartTime")();
            d << r->ReadLong("m_period")();
            d << r->ReadBool("m_autoCompass")();
            d << r->ReadInt("m_gfxId")();
            d << r->ReadBool("m_isMercenary")();
            d << r->ReadInt("m_mercenaryItemId")();
            d << r->ReadByte("m_mercenaryRank")();
            d << r->ReadInt("m_order")();
            d << r->ReadInt("m_id")();
            d << r->ReadString("m_successCriterion")();
            d << r->ReadIntArray("m_variableIds")();
            d << r->ReadInt("m_id")();
            d << r->ReadBool("m_feedback")();
            d << r->ReadBool("m_hasPositionFeedback")();
            d << r->ReadShort("m_positionX")();
            d << r->ReadShort("m_positionY")();
            d << r->ReadShort("m_positionZ")();
            d << r->ReadShort("m_positionWorldId")();
            d << r->ReadInt()();
            d << r->ReadInt("m_id")();
            d << r->ReadInt("m_type")();
            d << r->ReadIntArray("m_params")();

            data.push_back(d);
            r->FirstRow(false);
        }

        emit Finished(data);
    }
};
