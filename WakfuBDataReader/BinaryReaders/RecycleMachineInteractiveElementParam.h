#include "BaseBinaryReader.h"

class RecycleMachineInteractiveElementParam : public BaseBinaryReader
{
public:
    RecycleMachineInteractiveElementParam() {}

    QString GetColumns()
    {
        return QString("int|int");
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

            data.push_back(d);
        }

        emit Finished(data);
    }
};