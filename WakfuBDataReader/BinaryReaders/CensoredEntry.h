#include "BaseBinaryReader.h"

struct CensoredEntryBinaryData
{
    qint32 m_id;
    bool m_deepSearch;
    qint32 m_language;
    qint32 m_censorType;
    QString m_text;
};

class CensoredEntry : public BaseBinaryReader
{
public:
    CensoredEntry() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            CensoredEntryBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_deepSearch = r->ReadBool("m_deepSearch");
            entry.m_language = r->ReadInt("m_language");
            entry.m_censorType = r->ReadInt("m_censorType");
            entry.m_text = r->ReadString("m_text");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};