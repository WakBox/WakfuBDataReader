#include "BaseBinaryReader.h"

class InteractiveElementTemplate : public BaseBinaryReader
{
public:
    InteractiveElementTemplate() {}

    QString GetColumns()
    {
        return QString("int|short|short|int|int|short|short|bool|bool|bool|bool|byte|short|string|int");
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
            d << r->ReadShort();
            d << r->ReadShort();
            d << r->ReadInt(); // X
            d << r->ReadInt(); // Y
            d << r->ReadShort();
            d << r->ReadShort();

            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();

            d << r->ReadByte();
            d << r->ReadShort();

            // clg().intern()
            qint32 strSize = r->ReadInt();
            d << r->ReadString(strSize);

            d << r->ReadInt();

            // cli()
            qint32 intSize = r->ReadInt();
            qint32 j = 0;
            while (j < intSize)
            {
                r->ReadInt();
                ++j;
            }

            qint32 iEgSize = r->ReadInt();
            j = 0;
            while (j < iEgSize)
            {
                r->ReadInt();
                r->ReadInt();
                r->ReadShort();
                ++j;
            }

            qint32 iEhSize = r->ReadInt();
            j = 0;
            while (j < iEhSize)
            {
                r->ReadShort();
                r->ReadInt();
                ++j;
            }

            // cli()
            intSize = r->ReadInt();
            j = 0;
            while (j < intSize)
            {
                r->ReadInt();
                ++j;
            }


            data.push_back(d);
        }

        emit Finished(data);
    }
};
