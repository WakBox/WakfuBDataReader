#include "BaseBinaryReader.h"

class Tutorial : public BaseBinaryReader
{
public:
    Tutorial() {}

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
            for (quint32 i = 0; i < size; ++i)
                d << r->ReadInt("int");

            data.push_back(d);
            r->FirstRow(false);
        }

        emit Finished(data);
    }
};
