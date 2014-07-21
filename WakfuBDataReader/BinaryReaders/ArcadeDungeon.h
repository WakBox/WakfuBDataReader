#include "BaseBinaryReader.h"

class ArcadeDungeon : public BaseBinaryReader
{
public:
    ArcadeDungeon() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            // Struct
            r->ReadInt("ID");
            r->ReadShort("short");

            qint32 size = r->ReadInt(QString());
            for (quint32 i = 0; i < size; ++i)
            {
                r->ReadInt("ID");
                r->ReadFloat("X");
            }

            size = r->ReadInt(QString());
            for (quint32 i = 0; i < size; ++i)
            {
                r->ReadInt("ID");
                r->ReadInt("int");

                qint32 size2 = r->ReadInt(QString());
                for (quint32 j = 0; j < size2; ++j)
                {
                    r->ReadInt("int");
                    r->ReadInt("int");
                    r->ReadInt("int");
                    r->ReadByte("byte");
                }
            }

            size = r->ReadInt(QString());
            for (quint32 i = 0; i < size; ++i)
            {
                r->ReadInt("int");
                r->ReadInt("int");
                r->ReadInt("int");
                r->ReadInt("int");
                r->ReadInt("int");
            }

            r->ReadInt("int");
            r->ReadInt("int");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};
