#include "BaseBinaryReader.h"

// Call from other BinaryStorage reader...
class TravelLoading : public BaseBinaryReader
{
public:
    TravelLoading() {}

    QString GetColumns()
    {
        return QString("string|int|int|int");
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
            qint32 strSize = r->ReadInt();
            d << r->ReadString(strSize);

            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
