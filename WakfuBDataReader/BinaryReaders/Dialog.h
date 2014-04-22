#include "BaseBinaryReader.h"

class Dialog : public BaseBinaryReader
{
public:
    Dialog() {}

    QString GetColumns()
    {
        return QString("int|string|int");
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

            data.push_back(d);
        }

        emit Finished(data);
    }
};
