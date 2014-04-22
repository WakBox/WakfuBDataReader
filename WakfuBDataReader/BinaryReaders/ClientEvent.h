#include "BaseBinaryReader.h"

class ClientEvent : public BaseBinaryReader
{
public:
    ClientEvent() {}

    QString GetColumns()
    {
        return QString("int|int|short|short|string|string array|bool|int");
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
            d << r->ReadString();
            d << r->ReadStringArray();
            d << r->ReadBool();
            d << r->ReadInt();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
