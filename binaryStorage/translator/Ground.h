#include "BaseBinaryReader.h"

class Ground : public BaseBinaryReader
{
public:
    Ground() {}

    QString GetColumns()
    {
        return QString("int|int|int|short|int|short|short");
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
            d << r->ReadInt();
            d << r->ReadShort();
            d << r->ReadShort();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
