#include "BaseBinaryReader.h"

class AreaEffect : public BaseBinaryReader
{
public:
    AreaEffect() {}

    QString GetColumns()
    {
        return QString("int|int|int|int|int|bool|bool|bool|bool|bool|string|int array|int array|int array|int array|float array|float array|int array|int array|string|string|string|string|int");
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
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadString();
            d << r->ReadIntArray();
            d << r->ReadIntArray();
            d << r->ReadIntArray();
            d << r->ReadIntArray();
            d << r->ReadFloatArray();
            d << r->ReadFloatArray();
            d << r->ReadIntArray();
            d << r->ReadIntArray();
            d << r->ReadString();
            d << r->ReadString();
            d << r->ReadString();
            d << r->ReadString();
            d << r->ReadInt();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
