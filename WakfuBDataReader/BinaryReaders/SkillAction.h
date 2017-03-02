#ifndef SKILLACTION_H
#define SKILLACTION_H

#include "BaseBinaryReader.h"

struct SkillActionBinaryData
{
    qint32 m_id;
    qint32 m_mruGfxId;
    QString m_mruKey;
    QList<qint32> m_associatedItems;
    QString m_animLinkage;
};

class SkillAction : public BaseBinaryReader
{
public:
    SkillAction() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            SkillActionBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_mruGfxId = r->ReadInt("m_mruGfxId");
            entry.m_mruKey = r->ReadString("m_mruKey");
            entry.m_associatedItems = r->ReadIntArray("m_associatedItems");
            entry.m_animLinkage = r->ReadString("m_animLinkage");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif