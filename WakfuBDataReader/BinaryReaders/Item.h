#include "BaseBinaryReader.h"

class Item : public BaseBinaryReader
{
public:
    Item() {}

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
            r->ReadShort("ItemSet");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadShort("Item Level");
            r->ReadStringArray("string array");
            r->ReadInt("int");
            r->ReadShort("short");
            r->ReadByte("byte");
            r->ReadByte("byte");
            r->ReadByte("byte");
            r->ReadInt("int");
            r->ReadInt("int");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadBool("bool");
            r->ReadShort("short");
            r->ReadByte("byte");
            r->ReadString("string");
            r->ReadIntArray("int array");
            r->ReadByte("byte");
            r->ReadByte("byte");
            r->ReadByte("byte");
            r->ReadByte("byte");
            r->ReadIntArray("int array");

            qint32 size = r->ReadInt(QString());
            for (quint32 i = 0; i < size; ++i)
            {
                r->ReadInt("int");
                r->ReadInt("int");
                r->ReadBool("bool");
                r->ReadBool("bool");
                r->ReadBool("bool");
                r->ReadBool("bool");
                r->ReadString("string");
                r->ReadStringArray("String array");
                r->ReadStringArray("String array");
            }

            r->ReadIntArray("int array");
            r->ReadByteArray("byte array");
            r->ReadByteArray("byte array");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};
