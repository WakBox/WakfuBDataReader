#include "BaseBinaryReader.h"

class AlmanachDate : public BaseBinaryReader
{
public:
    AlmanachDate() {}

    QString GetColumns()
    {
        return QString("int ID|long timestamp|int");
    }

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            QVariantList d;

            r->SetBufferPosition(row.offset);

            // Struct
            d << r->ReadInt();
            d << r->ReadLong();
            d << r->ReadInt();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
