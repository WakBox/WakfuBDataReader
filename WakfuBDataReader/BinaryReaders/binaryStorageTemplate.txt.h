#include "BaseBinaryReader.h"

class binaryStorageTemplate.txt : public BaseBinaryReader
{
public:
    binaryStorageTemplate.txt() {}

    QString GetColumns()
    {
        return QString("");
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

            data.push_back(d);
        }

        emit Finished(data);
    }
};
