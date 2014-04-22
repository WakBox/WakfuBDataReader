#include "BaseBinaryReader.h"

class BoatLink : public BaseBinaryReader
{
public:
    BoatLink() {}

    QString GetColumns()
    {
        return QString("int|int|int|int|string|string|bool");
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
            d << r->ReadInt();
            d << r->ReadString();
            d << r->ReadString();
            d << r->ReadBool();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
