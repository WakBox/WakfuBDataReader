#include "BaseBinaryReader.h"

class Achievement : public BaseBinaryReader
{
public:
    Achievement() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            // Struct
            r->ReadInt("ID");
            r->ReadInt("int");
            r->ReadBool("IsVisible");
            r->ReadBool("bool");
            r->ReadBool("IsActive");
            r->ReadString("string");

            qint32 size = r->ReadInt(QString());
            for (quint32 i = 0; i < size; ++i)
            {
                r->ReadInt("int");
                r->ReadBool("bool");
                r->ReadBool("bool");
                r->ReadShort("short");
                r->ReadShort("short");
                r->ReadShort("short");
                r->ReadShort("short");

                qint32 size2 = r->ReadInt(QString());
                for (quint32 j = 0; j < size2; ++j)
                {
                    r->ReadInt("int");
                    r->ReadString("string");
                    r->ReadIntArray("intArray");
                }
            }

            size = r->ReadInt(QString());
            for (quint32 i = 0; i < size; ++i)
            {
                r->ReadInt("int");
                r->ReadInt("int");
                r->ReadIntArray("intArray");
            }

            r->ReadInt("Duration");
            r->ReadInt("int");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadBool("bool");
            r->ReadInt("int");
            r->ReadLong("long");
            r->ReadLong("long");
            r->ReadBool("bool");
            r->ReadInt("int");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};
