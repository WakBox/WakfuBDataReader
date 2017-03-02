#include "BaseBinaryReader.h"

struct ProtectorFaunaProtection
{
    qint32 m_monsterFamilyId;
    qint32 m_protectionCost;
    qint32 m_reintroductionCost;
    qint32 m_reintroductionItemId;
    qint16 m_reintroductionItemQty;
};

struct ProtectorFloraProtection
{
    qint32 m_resourceFamilyId;
    qint32 m_protectionCost;
    qint32 m_reintroductionCost;
    qint32 m_reintroductionItemId;
    qint16 m_reintroductionItemQty;
};

struct ProtectorEcosystemProtectionBinaryData
{
    qint32 m_protectorId;
    QList<ProtectorFaunaProtection> m_faunaProtection;
    QList<ProtectorFloraProtection> m_floraProtection;
};

class ProtectorEcosystemProtection : public BaseBinaryReader
{
public:
    ProtectorEcosystemProtection() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            ProtectorEcosystemProtectionBinaryData entry;

            entry.m_protectorId = r->ReadInt("m_protectorId");

            qint32 faunaProtectionCount = r->ReadInt();

            for (qint32 i = 0; i < faunaProtectionCount; ++i)
            {
                ProtectorFaunaProtection protectorFaunaProtection;

                protectorFaunaProtection.m_monsterFamilyId = r->ReadInt();
                protectorFaunaProtection.m_protectionCost = r->ReadInt();
                protectorFaunaProtection.m_reintroductionCost = r->ReadInt();
                protectorFaunaProtection.m_reintroductionItemId = r->ReadInt();
                protectorFaunaProtection.m_reintroductionItemQty = r->ReadShort();

                entry.m_faunaProtection.push_back(protectorFaunaProtection);
            }


            qint32 floraProtectionCount = r->ReadInt();

            for (qint32 i = 0; i < floraProtectionCount; ++i)
            {
                ProtectorFloraProtection protectorFloraProtection;

                protectorFloraProtection.m_resourceFamilyId = r->ReadInt();
                protectorFloraProtection.m_protectionCost = r->ReadInt();
                protectorFloraProtection.m_reintroductionCost = r->ReadInt();
                protectorFloraProtection.m_reintroductionItemId = r->ReadInt();
                protectorFloraProtection.m_reintroductionItemQty = r->ReadShort();

                entry.m_floraProtection.push_back(protectorFloraProtection);
            }


            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};