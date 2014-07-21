#include "BaseBinaryReader.h"

class Bags : public BaseBinaryReader
{
public:
    Bags() {}

    QString GetColumns()
    {
        return QString("int ID|short|int|int array");
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
            d << r->ReadInt();
            d << r->ReadIntArray();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
