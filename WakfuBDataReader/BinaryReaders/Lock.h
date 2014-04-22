#include "BaseBinaryReader.h"

class Lock : public BaseBinaryReader
{
public:
    Lock() {}

    QString GetColumns()
    {
        return QString("int|int|int|long|long|bool");
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
            d << r->ReadLong();
            d << r->ReadLong();
            d << r->ReadBool();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
