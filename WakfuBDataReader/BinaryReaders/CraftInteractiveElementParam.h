#include "BaseBinaryReader.h"

class CraftInteractiveElementParam : public BaseBinaryReader
{
public:
    CraftInteractiveElementParam() {}

    QString GetColumns()
    {
        return QString("int|int|int|int|int array|byte");
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
            d << r->ReadInt();
            d << r->ReadIntArray();
            d << r->ReadByte();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
