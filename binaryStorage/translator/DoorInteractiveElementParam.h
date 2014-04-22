#include "BaseBinaryReader.h"

class DoorInteractiveElementParam : public BaseBinaryReader
{
public:
    DoorInteractiveElementParam() {}

    QString GetColumns()
    {
        return QString("int|int|bool|int|int|string");
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
            d << r->ReadBool();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadString();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
