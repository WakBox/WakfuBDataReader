#include "BaseBinaryReader.h"

struct EmoteBinaryData
{
    qint32 m_id;
    qint16 m_type;
    QString m_cmd;
    bool m_needTarget;
    bool m_moveToTarget;
    bool m_infiniteDuration;
    bool m_isMusical;
    QList<QString> m_scriptParams;
};

class Emote : public BaseBinaryReader
{
public:
    Emote() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            EmoteBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_type = r->ReadShort("m_type");
            entry.m_cmd = r->ReadString("m_cmd");
            entry.m_needTarget = r->ReadBool("m_needTarget");
            entry.m_moveToTarget = r->ReadBool("m_moveToTarget");
            entry.m_infiniteDuration = r->ReadBool("m_infiniteDuration");
            entry.m_isMusical = r->ReadBool("m_isMusical");
            entry.m_scriptParams = r->ReadStringArray("m_scriptParams");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};