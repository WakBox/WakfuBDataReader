#include "BaseBinaryReader.h"

class InteractiveElementTemplate : public BaseBinaryReader
{
public:
    InteractiveElementTemplate() {}

    QString GetColumns()
    {
        return QString("int|short|short|int|int|short|short|bool|bool|bool|bool|byte|short|string|int|int array|int|int|short|int|int array");
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
            d << r->ReadShort();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadByte();
            d << r->ReadShort();
            d << r->ReadString();
            d << r->ReadInt();
            d << r->ReadIntArray();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadShort();
            d << r->ReadInt();
            d << r->ReadIntArray();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
