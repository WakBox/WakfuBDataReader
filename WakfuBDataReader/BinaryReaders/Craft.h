#include "BaseBinaryReader.h"

class Craft : public BaseBinaryReader
{
public:
    Craft() {}

    QString GetColumns()
    {
        return QString("int|int|float|bool|bool|bool");
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
            d << r->ReadFloat();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
