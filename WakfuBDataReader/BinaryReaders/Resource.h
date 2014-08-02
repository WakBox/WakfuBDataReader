#include "BaseBinaryReader.h"

class Resource : public BaseBinaryReader
{
public:
    Resource() {}

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
            d << r->ReadInt("Ressource Id");
            d << r->ReadInt("Type");
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadBool("IsBlocking");
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadShort();
            d << r->ReadIntArray();
            d << r->ReadIntArray();

            data.push_back(d);
            break;

            qint32 size = r->ReadInt(QString());
            for (qint32 i = 0; i < size; ++i)
            {
                d << r->ReadInt("Index");
                qint32 size = r->ReadInt(QString());
                for (qint32 i = 0; i < size; ++i)
                {
                    d << r->ReadInt();
                    d << r->ReadInt();
                    d << r->ReadInt();
                    d << r->ReadInt();
                    d << r->ReadInt();
                    d << r->ReadInt();
                    d << r->ReadInt();
                    d << r->ReadInt();
                    d << r->ReadInt();
                    d << r->ReadString();
                    d << r->ReadInt();
                    d << r->ReadInt();
                    d << r->ReadIntArray();
                    d << r->ReadInt();
                    d << r->ReadBool();
                }

                d << r->ReadInt();
                d << r->ReadInt();
                d << r->ReadInt();
                d << r->ReadInt();
                d << r->ReadInt();
            }

            d << r->ReadShort();
            d << r->ReadInt();

            size = r->ReadInt();
            for (qint32 i = 0; i < size; ++i)
            {
                d << r->ReadInt();
                d << r->ReadIntArray();
            }

            data.push_back(d);
            r->FirstRow(false);
        }

        emit Finished(data);
    }
};
