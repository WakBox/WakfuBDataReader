#include "BaseBinaryReader.h"

class Emote : public BaseBinaryReader
{
public:
    Emote() {}

    QString GetColumns()
    {
        return QString("int|short|string|bool|bool|bool|bool|string");
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

            // public String clg()
            qint32 strSize = r->ReadInt();
            d << r->ReadString(strSize);

            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();
            d << r->ReadBool();

            // public String[] ceT()
            qint32 strNum = r->ReadInt();
            qDebug() << strNum;
            QStringList str;

            for (qint16 j = 0; j < strNum; ++j)
            {
                qint32 strSize = r->ReadInt();
                str << r->ReadString(strSize);
            }

            d << str.join("|");

            data.push_back(d);
        }

        emit Finished(data);
    }
};
