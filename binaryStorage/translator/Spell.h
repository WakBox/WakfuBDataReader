#include "BaseBinaryReader.h"

class Spell : public BaseBinaryReader
{
public:
    Spell() {}

    QString GetColumns()
    {
        return QString("int|int|int|short|short|short|short|float|short|bool|bool|bool|bool|bool|bool|int|string|float|float|float|float|float|float|float|float|float|float|short|short|short|short|short|string|bool|bool|bool|int array|bool|bool|bool|bool|bool|bool|int array|int|int|string");
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
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadFloat();
            d << r->ReadShort();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadInt();
            d << r->ReadString();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadString();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadIntArray();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadIntArray();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadString();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
