#include "BaseBinaryReader.h"

class AlmanachEntry : public BaseBinaryReader
{
public:
    AlmanachEntry() {}

    QString GetColumns()
    {
        return QString("int ID|int|int|int array");
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
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadIntArray();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
