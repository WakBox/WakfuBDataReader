#include "BaseBinaryReader.h"

class ClientEvent : public BaseBinaryReader
{
public:
    ClientEvent() {}

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
            d << r->ReadInt("Id");
            d << r->ReadInt("Type");
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadString();
            d << r->ReadStringArray();
            d << r->ReadBool();

            qint32 size = r->ReadInt(QString());
            for (quint32 i = 0; i < size; ++i)
            {
                d << r->ReadInt("ID");
                d << r->ReadShort("short");
                d << r->ReadString("string");

                qint32 size2 = r->ReadInt(QString());
                for (quint32 j = 0; j < size2; ++j)
                {
                    d << r->ReadInt("ID");
                    d << r->ReadInt("Type");
                    d << r->ReadStringArray("Params");
                }
            }

            data.push_back(d);
            r->FirstRow(false);
        }

        emit Finished(data);
    }
};
