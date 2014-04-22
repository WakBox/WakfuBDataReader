#include "BaseBinaryReader.h"

class NationLaw : public BaseBinaryReader
{
public:
    NationLaw() {}

    QString GetColumns()
    {
        return QString("int|int|string array|int|int|int|bool|bool|bool|bool|int array");
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
            d << r->ReadStringArray();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadIntArray();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
