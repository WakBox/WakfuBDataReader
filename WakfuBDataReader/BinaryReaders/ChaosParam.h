#include "BaseBinaryReader.h"

class ChaosParam : public BaseBinaryReader
{
public:
    ChaosParam() {}

    QString GetColumns()
    {
        return r->GetColumns();
    }

    void Read(Rows rows)
    {
        qint32 size = rows.size();
        r->FirstRow();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            QVariantList d;

            r->SetBufferPosition(row.offset);

            // Struct
            d << r->ReadByte();
            d << r->ReadInt();

            data.push_back(d);
            r->FirstRow(false);
        }

        emit Finished(data);
    }
};
