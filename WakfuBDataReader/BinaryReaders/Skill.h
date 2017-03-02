#ifndef SKILL_H
#define SKILL_H

#include "BaseBinaryReader.h"

struct SkillBinaryData
{
    qint32 m_id;
    qint32 m_type;
    qint32 m_scriptId;
    qint32 m_mruGfxId;
    QString m_mruKey;
    QString m_animLinkage;
    QList<qint32> m_associatedItemTypes;
    QList<qint32> m_associatedItems;
    qint32 m_maxLevel;
    bool m_isInnate;
};

class Skill : public BaseBinaryReader
{
public:
    Skill() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            SkillBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_type = r->ReadInt("m_type");
            entry.m_scriptId = r->ReadInt("m_scriptId");
            entry.m_mruGfxId = r->ReadInt("m_mruGfxId");
            entry.m_mruKey = r->ReadString("m_mruKey");
            entry.m_animLinkage = r->ReadString("m_animLinkage");
            entry.m_associatedItemTypes = r->ReadIntArray("m_associatedItemTypes");
            entry.m_associatedItems = r->ReadIntArray("m_associatedItems");
            entry.m_maxLevel = r->ReadInt("m_maxLevel");
            entry.m_isInnate = r->ReadBool("m_isInnate");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif