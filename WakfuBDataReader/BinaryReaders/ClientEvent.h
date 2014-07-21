#include "BaseBinaryReader.h"

class ClientEvent : public BaseBinaryReader
{
public:
    ClientEvent() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            // Struct
            r->ReadInt("ID");
            r->ReadInt("Type");
            r->ReadShort("short");
            r->ReadShort("short");
            r->ReadString("string");
            r->ReadStringArray("string array");
            r->ReadBool("bool");

            qint32 size = r->ReadInt(QString());
            for (quint32 i = 0; i < size; ++i)
            {
                r->ReadInt("ID");
                r->ReadShort("short");
                r->ReadString("string");

                qint32 size2 = r->ReadInt(QString());
                for (quint32 j = 0; j < size2; ++j)
                {
                    r->ReadInt("ID");
                    r->ReadInt("Type");
                    r->ReadStringArray("Params");
                }
            }

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};
