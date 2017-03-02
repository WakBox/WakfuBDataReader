#include "BaseBinaryReader.h"

struct Answer
{
    qint32 m_id;
    QString m_criterion;
    qint32 m_type;
    bool m_clientOnly;
};

struct DialogBinaryData
{
    qint32 m_id;
    QString m_criteria;
    QList<Answer> m_answers;
};

class Dialog : public BaseBinaryReader
{
public:
    Dialog() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            DialogBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_criteria = r->ReadString("m_criteria");

            qint32 answerCount = r->ReadInt();

            for (qint32 i = 0; i < answerCount; ++i)
            {
                Answer answer;

                answer.m_id = r->ReadInt();
                answer.m_criterion = r->ReadString();
                answer.m_type = r->ReadInt();
                answer.m_clientOnly = r->ReadBool();

                entry.m_answers.push_back(answer);
            }


            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};