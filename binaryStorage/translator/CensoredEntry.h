#include "BaseBinaryReader.h"

class CensoredEntry : public BaseBinaryReader
{
public:
    CensoredEntry() {}

    QString GetColumns()
    {
        return QString("int|bool|int|int|string");
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
            d << r->ReadBool();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadString();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
