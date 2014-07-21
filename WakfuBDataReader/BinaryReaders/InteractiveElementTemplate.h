#include "BaseBinaryReader.h"

class InteractiveElementTemplate : public BaseBinaryReader
{
public:
    InteractiveElementTemplate() {}

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
            r->ReadShort("short");
            r->ReadInt("X");
            r->ReadInt("Y");
            r->ReadShort("short");
            r->ReadShort("short");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadByte("byte");
            r->ReadShort("short");
            r->ReadString("string");
            r->ReadInt("int");
            r->ReadIntArray("int array");

            qint32 size = r->ReadInt(QString());
            for (quint32 i = 0; i < size; ++i)
            {
                QString j = QString::number(i);
                r->ReadInt("X [" + j + "]");
                r->ReadInt("Y [" + j + "]");
                r->ReadShort("short [" + j + "]");
            }

            size = r->ReadInt(QString());
            for (quint32 i = 0; i < size; ++i)
            {
                QString j = QString::number(i);
                r->ReadShort("short [" + j + "]");
                r->ReadInt("int [" + j + "]");
            }

            r->ReadIntArray("int array");
            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};
