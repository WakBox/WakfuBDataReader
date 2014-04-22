#include "BaseBinaryReader.h"

class ItemType : public BaseBinaryReader
{
public:
    ItemType() {}

    QString GetColumns()
    {
        return QString("short|short|bool|bool|bool|string[]|string[]");
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
            d << r->ReadShort();
            d << r->ReadShort();

            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();

            for (quint8 j = 0; j < 2; ++j)
            {
                qint32 strNum = r->ReadInt();
                QStringList str;

                for (qint16 j = 0; j < strNum; ++j)
                {
                    qint32 strSize = r->ReadInt();
                    str << r->ReadString(strSize);
                }

                d << str.join("|");
            }


            data.push_back(d);
        }

        emit Finished(data);
    }
};
