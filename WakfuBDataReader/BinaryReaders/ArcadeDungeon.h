#include "BaseBinaryReader.h"

class ArcadeDungeon : public BaseBinaryReader
{
public:
    ArcadeDungeon() {}

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
            d << r->ReadInt("ID");
            d << r->ReadShort("short");

            qint32 size = r->ReadInt(QString());
            for (quint32 i = 0; i < size; ++i)
            {
                d << r->ReadInt("ID");
                d << r->ReadFloat("X");
            }

            size = r->ReadInt(QString());
            for (quint32 i = 0; i < size; ++i)
            {
                d << r->ReadInt("ID");
                d << r->ReadInt("int");

                qint32 size2 = r->ReadInt(QString());
                for (quint32 j = 0; j < size2; ++j)
                {
                    d << r->ReadInt("int");
                    d << r->ReadInt("int");
                    d << r->ReadInt("int");
                    d << r->ReadByte("byte");
                }
            }

            size = r->ReadInt(QString());
            for (quint32 i = 0; i < size; ++i)
            {
                d << r->ReadInt("int");
                d << r->ReadInt("int");
                d << r->ReadInt("int");
                d << r->ReadInt("int");
                d << r->ReadInt("int");
            }

            d << r->ReadInt("int");
            d << r->ReadInt("int");

            data.push_back(d);
            r->FirstRow(false);
        }

        emit Finished(data);
    }
};
