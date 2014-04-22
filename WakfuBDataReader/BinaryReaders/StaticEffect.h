#include "BaseBinaryReader.h"

class StaticEffect : public BaseBinaryReader
{
public:
    StaticEffect() {}

    QString GetColumns()
    {
        return QString("int|int|int|short|int array|short|short|int array|short|int array|int array|int array|int array|int array|int array|int array|string|long array|bool|int|float|bool|bool|short|float|float array|float|float|bool|short|float|bool|string|short|short|string|string|string|bool|bool|bool|bool|bool|bool|int|bool|int array|bool|bool|bool|bool|bool");
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
            d << r->ReadShort();
            d << r->ReadIntArray();
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadIntArray();
            d << r->ReadShort();
            d << r->ReadIntArray();
            d << r->ReadIntArray();
            d << r->ReadIntArray();
            d << r->ReadIntArray();
            d << r->ReadIntArray();
            d << r->ReadIntArray();
            d << r->ReadIntArray();
            d << r->ReadString();
            d << r->ReadLongArray();
            d << r->ReadBool();
            d << r->ReadInt();
            d << r->ReadFloat();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadShort();
            d << r->ReadFloat();
            d << r->ReadFloatArray();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadBool();
            d << r->ReadShort();
            d << r->ReadFloat();
            d << r->ReadBool();
            d << r->ReadString();
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadString();
            d << r->ReadString();
            d << r->ReadString();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadInt();
            d << r->ReadBool();
            d << r->ReadIntArray();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
