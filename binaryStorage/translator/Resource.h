#include "BaseBinaryReader.h"

class Resource : public BaseBinaryReader
{
public:
    Resource() {}

    QString GetColumns()
    {
        return QString("int|int|short|short|short|short|bool|bool|bool|short|int array|int array|int|short|int|int|int|int array");
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
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadShort();
            d << r->ReadIntArray();
            d << r->ReadIntArray();
            d << r->ReadInt();
            d << r->ReadShort();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadIntArray();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
