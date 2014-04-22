#include "BaseBinaryReader.h"

class EquipableDummyInteractiveElementParam : public BaseBinaryReader
{
public:
    EquipableDummyInteractiveElementParam() {}

    QString GetColumns()
    {
        return QString("int|string");
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

            data.push_back(d);
        }

        emit Finished(data);
    }
};
