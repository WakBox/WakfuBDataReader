#include "BaseBinaryReader.h"

class HavenBagModelView : public BaseBinaryReader
{
public:
    HavenBagModelView() {}

    QString GetColumns()
    {
        return QString("int|bool|bool|int|bool");
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
            d << r->ReadBool();
            d << r->ReadInt();
            d << r->ReadBool();

            data.push_back(d);
        }

        emit Finished(data);
    }
};
