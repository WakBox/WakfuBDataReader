#ifndef EQUIPABLEDUMMYINTERACTIVEELEMENTPARAM_H
#define EQUIPABLEDUMMYINTERACTIVEELEMENTPARAM_H

#include "BaseBinaryReader.h"

struct EquipableDummyInteractiveElementParamBinaryData
{
    qint32 m_id;
    QString m_animName;
    qint8 m_sex;
};

class EquipableDummyInteractiveElementParam : public BaseBinaryReader
{
public:
    EquipableDummyInteractiveElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            EquipableDummyInteractiveElementParamBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_animName = r->ReadString("m_animName");
            entry.m_sex = r->ReadByte("m_sex");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif