#ifndef BACKGROUNDFEEDBACK_H
#define BACKGROUNDFEEDBACK_H

#include "BaseBinaryReader.h"

struct Page
{
    qint32 m_id;
    qint16 m_order;
    qint16 m_template;
    qint32 m_imageId;
};

struct BackgroundFeedbackBinaryData
{
    qint32 m_id;
    qint16 m_type;
    QList<Page> m_pages;
};

class BackgroundFeedback : public BaseBinaryReader
{
public:
    BackgroundFeedback() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            BackgroundFeedbackBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_type = r->ReadShort("m_type");

            qint32 pageCount = r->ReadInt();

            for (qint32 i = 0; i < pageCount; ++i)
            {
                Page page;

                page.m_id = r->ReadInt();
                page.m_order = r->ReadShort();
                page.m_template = r->ReadShort();
                page.m_imageId = r->ReadInt();

                entry.m_pages.push_back(page);
            }


            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};

#endif