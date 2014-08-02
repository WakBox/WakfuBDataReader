#include "BaseBinaryReader.h"

class Aptitude : public BaseBinaryReader
{
public:
    Aptitude() {}

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
            d << r->ReadInt("Aptitude Id");
            d << r->ReadShort();
            d << r->ReadByte();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadShort();
            d << r->ReadInt();
            d << r->ReadIntArray();
            d << r->ReadInt();
            d << r->ReadIntArray();
            d << r->ReadIntArray();

            data.push_back(d);
            r->FirstRow(false);
        }

        emit Finished(data);
    }
};
