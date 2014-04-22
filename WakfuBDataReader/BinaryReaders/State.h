#include "BaseBinaryReader.h"

class State : public BaseBinaryReader
{
public:
    State() {}

    QString GetColumns()
    {
        return QString("int|short|int array|int array|float array|bool|bool|bool|bool|bool|string|string|bool|bool|int array|int array|bool|bool|byte|byte|bool|bool|int|bool");
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
            d << r->ReadShort();
            d << r->ReadIntArray();
            d << r->ReadIntArray();
            d << r->ReadFloatArray();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadString();
            d << r->ReadString();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadIntArray();
            d << r->ReadIntArray();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadByte();
            d << r->ReadByte();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadInt();
            d << r->ReadBool();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
