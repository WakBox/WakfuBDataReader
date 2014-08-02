#include "BaseBinaryReader.h"

class State : public BaseBinaryReader
{
public:
    State() {}

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
            d << r->ReadInt();
            d << r->ReadShort();
            d << r->ReadIntArray();
            d << r->ReadIntArray();
            d << r->ReadFloatArray();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadString();
            d << r->ReadString();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadIntArray();
            d << r->ReadIntArray();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadByte();
            d << r->ReadByte();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadInt();
            d << r->ReadBool();

            data.push_back(d);
            r->FirstRow(false);
        }

        emit Finished(data);
    }
};
