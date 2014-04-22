#include "BaseBinaryReader.h"

class Zaap : public BaseBinaryReader
{
public:
    Zaap() {}

    QString GetColumns()
    {
        return QString("int|int|int|int|int|int|bool|string");
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
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadBool();
            d << r->ReadString();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
