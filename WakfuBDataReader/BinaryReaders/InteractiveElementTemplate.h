#include "BaseBinaryReader.h"

class InteractiveElementTemplate : public BaseBinaryReader
{
public:
    InteractiveElementTemplate() {}

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
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadInt("X");
            d << r->ReadInt("Y");
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadByte();
            d << r->ReadShort();
            d << r->ReadString();
            d << r->ReadInt();
            d << r->ReadIntArray();


            qint32 size = r->ReadInt(QString());
            for (quint32 i = 0; i < size; ++i)
            {
                QString j = QString::number(i);
                d << r->ReadInt("X [" + j + "]");
                d << r->ReadInt("Y [" + j + "]");
                d << r->ReadShort("short [" + j + "]");
            }

            size = r->ReadInt(QString());
            for (quint32 i = 0; i < size; ++i)
            {
                QString j = QString::number(i);
                d << r->ReadShort("short [" + j + "]");
                d << r->ReadInt("int [" + j + "]");
            }

            d << r->ReadIntArray("int array");

            data.push_back(d);
            r->FirstRow(false);
        }

        emit Finished(data);
    }
};
