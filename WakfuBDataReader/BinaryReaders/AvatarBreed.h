#include "BaseBinaryReader.h"

class AvatarBreed : public BaseBinaryReader
{
public:
    AvatarBreed() {}

    QString GetColumns()
    {
        return QString("int|string|int|int|int|int|int|int|int|int|int|int|int|int|int|int|int|byte array|float array");
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
            d << r->ReadString();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadByteArray();
            d << r->ReadFloatArray();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
