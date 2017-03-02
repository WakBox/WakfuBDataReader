#include "BaseBinaryReader.h"

struct NationLawBinaryData
{
    qint32 m_id;
    qint32 m_lawConstantId;
    QList<QString> m_params;
    qint32 m_basePointsModification;
    qint32 m_percentPointsModification;
    qint32 m_lawPointCost;
    bool m_lawLocked;
    bool m_applicableToCitizen;
    bool m_applicableToAlliedForeigner;
    bool m_applicableToNeutralForeigner;
    QList<qint32> m_restrictedNations;
};

class NationLaw : public BaseBinaryReader
{
public:
    NationLaw() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            NationLawBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_lawConstantId = r->ReadInt("m_lawConstantId");
            entry.m_params = r->ReadStringArray("m_params");
            entry.m_basePointsModification = r->ReadInt("m_basePointsModification");
            entry.m_percentPointsModification = r->ReadInt("m_percentPointsModification");
            entry.m_lawPointCost = r->ReadInt("m_lawPointCost");
            entry.m_lawLocked = r->ReadBool("m_lawLocked");
            entry.m_applicableToCitizen = r->ReadBool("m_applicableToCitizen");
            entry.m_applicableToAlliedForeigner = r->ReadBool("m_applicableToAlliedForeigner");
            entry.m_applicableToNeutralForeigner = r->ReadBool("m_applicableToNeutralForeigner");
            entry.m_restrictedNations = r->ReadIntArray("m_restrictedNations");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};