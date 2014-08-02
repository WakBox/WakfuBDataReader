#include "BaseBinaryReader.h"

class Ground : public BaseBinaryReader
{
public:
    Ground() {}

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
            d << r->ReadInt("Id");
            qint32 size = r->ReadInt(QString());
            for (qint32 i = 0; i < size; ++i)
            {
                d << r->ReadInt();
                d << r->ReadShort();
            }

            size = r->ReadInt(QString());
            for (qint32 i = 0; i < size; ++i)
            {
                d << r->ReadShort();
                d << r->ReadShort();
            }

            data.push_back(d);
            r->FirstRow(false);
        }

        emit Finished(data);
    }
};
