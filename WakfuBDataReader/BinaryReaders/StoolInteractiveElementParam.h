#include "BaseBinaryReader.h"

class StoolInteractiveElementParam : public BaseBinaryReader
{
public:
    StoolInteractiveElementParam() {}

    QString GetColumns()
    {
        return QString("int|string|int|byte");
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
            d << r->ReadString();
            d << r->ReadInt();
            d << r->ReadByte();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
