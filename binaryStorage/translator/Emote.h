#include "BaseBinaryReader.h"

class Emote : public BaseBinaryReader
{
public:
    Emote() {}

    QString GetColumns()
    {
        return QString("int|short|string|bool|bool|bool|bool|string array");
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
            d << r->ReadString();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadStringArray();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
