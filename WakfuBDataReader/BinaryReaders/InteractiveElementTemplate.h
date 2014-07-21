#include "BaseBinaryReader.h"

class InteractiveElementTemplate : public BaseBinaryReader
{
public:
    InteractiveElementTemplate() {}

    QString GetColumns()
    {
        return QString("int|short|short|int|int|short|short|bool|bool|bool|bool|byte|short|string|int|int array|int|int|short|int|int array");
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
            r->ReadInt();
            r->ReadShort();
            r->ReadShort();
            r->ReadInt();
            r->ReadInt();
            r->ReadShort();
            r->ReadShort();
            r->ReadBool();
            r->ReadBool();
            r->ReadBool();
            r->ReadBool();
            r->ReadByte();
            r->ReadShort();

            r->ReadString();

            r->ReadInt();
            r->ReadIntArray();

            int intSize = r->ReadInt();
            intSize;
            for (int i = 0; i < intSize; ++i)
            {
                r->ReadInt();
                r->ReadInt();
                r->ReadShort();
            }

            r->ReadInt();
            r->ReadShort();
            r->ReadInt();
            r->ReadIntArray();

            r->PushRow();
        }

        emit Finished(data);
    }
};
