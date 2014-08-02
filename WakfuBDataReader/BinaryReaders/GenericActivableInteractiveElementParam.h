#include "BaseBinaryReader.h"

class GenericActivableInteractiveElementParam : public BaseBinaryReader
{
public:
    GenericActivableInteractiveElementParam() {}

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

            qint32 size = r->ReadInt(QString());
            for (qint32 i = 0; i < size; ++i)
            {
                d << r->ReadInt();
                d << r->ReadInt();
                d << r->ReadInt();
                d << r->ReadInt();
                d << r->ReadBool();
                d << r->ReadInt();

                qint32 size = r->ReadInt(QString());
                for (qint32 i = 0; i < size; ++i)
                {
                    d << r->ReadInt();
                    d << r->ReadString();
                    d << r->ReadFloat();

                    qint32 size = r->ReadInt(QString());
                    for (qint32 i = 0; i < size; ++i)
                    {
                        d << r->ReadInt();
                        d << r->ReadInt();
                        d << r->ReadString();
                        d << r->ReadStringArray();
                    }
                }
            }

            qint8 hasChaosParam = r->ReadByte(QString());

            if (hasChaosParam)
            {
                d << r->ReadByte();
                d << r->ReadInt();
            }

            data.push_back(d);
            r->FirstRow(false);
        }

        emit Finished(data);
    }
};
