#include "BaseBinaryReader.h"

class ChaosParam : public BaseBinaryReader
{
public:
    ChaosParam() {}

    QString GetColumns()
    {
        return QString("int");
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

            data.push_back(d);
        }

        emit Finished(data);
    }
};
