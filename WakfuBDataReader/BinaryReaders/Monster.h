#include "BaseBinaryReader.h"

class Monster : public BaseBinaryReader
{
public:
    Monster() {}

    QString GetColumns()
    {
        return QString("int|int|short|short|float|float|int|int|int|int|int|int|int|int|int|int|int|float|float|float|float|float|float|float|float|float|float|int|int|int|int|int|int|int|int|int|int|int|int|int|int|int|int|float|float|float|float|float|float|float|float|float|float|float|float|float|float|bool|short|short|short|int|int array|int array|short array|int|byte|short|short|short|short|int|int|int|int|int|short|int|int|int|int array|int|int|int|int|int");
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
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadFloat();
            d << r->ReadFloat();
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
            d << r->ReadInt();
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
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadFloat();
            d << r->ReadBool();
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadInt();
            d << r->ReadIntArray();
            d << r->ReadIntArray();
            d << r->ReadShortArray();
            d << r->ReadInt();
            d << r->ReadByte();
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadShort();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadIntArray();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
