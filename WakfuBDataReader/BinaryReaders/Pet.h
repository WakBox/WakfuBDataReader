#include "BaseBinaryReader.h"

class Pet : public BaseBinaryReader
{
public:
    Pet() {}

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
            d << r->ReadInt("Pet Id");
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadInt();
            d << r->ReadLong();
            d << r->ReadLong();
            d << r->ReadByte("Level ?");
            d << r->ReadShort("Level ?");
            d << r->ReadShort("Level ?");

            qint32 size = r->ReadInt(QString());
            for (qint32 i = 0; i < size; ++i)
            {
                d << r->ReadByte();
                d << r->ReadByte();
            }

            size = r->ReadInt(QString());
            for (qint32 i = 0; i < size; ++i)
            {
                d << r->ReadInt();
                d << r->ReadInt();
            }

            size = r->ReadInt(QString());
            for (qint32 i = 0; i < size; ++i)
            {
                d << r->ReadInt();
                d << r->ReadBool();
            }

            size = r->ReadInt(QString());
            for (qint32 i = 0; i < size; ++i)
            {
                d << r->ReadInt();
                d << r->ReadLong();
            }

            d << r->ReadIntArray();

            size = r->ReadInt(QString());
            for (qint32 i = 0; i < size; ++i)
            {
                d << r->ReadInt();
                d << r->ReadInt();
                d << r->ReadInt();
            }

            data.push_back(d);
            r->FirstRow(false);
        }

        emit Finished(data);
    }
};
