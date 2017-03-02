#include "BaseBinaryReader.h"

struct Compartment
{
    qint32 m_uid;
    qint32 m_boxId;
    qint32 m_unlockItemId;
    qint8 m_capacity;
    qint32 m_compartmentOrder;
};

struct StorageBoxBinaryData
{
    qint32 m_id;
    qint32 m_visualId;
    qint8 if (buffer.get() != 0) {;
    QList<Compartment> m_compartments;
};

class StorageBox : public BaseBinaryReader
{
public:
    StorageBox() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            StorageBoxBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_visualId = r->ReadInt("m_visualId");
            entry.if (buffer.get() != 0) { = r->ReadByte("if (buffer.get() != 0) {");

            qint32 compartmentCount = r->ReadInt();

            for (qint32 i = 0; i < compartmentCount; ++i)
            {
                Compartment compartment;

                compartment.m_uid = r->ReadInt();
                compartment.m_boxId = r->ReadInt();
                compartment.m_unlockItemId = r->ReadInt();
                compartment.m_capacity = r->ReadByte();
                compartment.m_compartmentOrder = r->ReadInt();

                entry.m_compartments.push_back(compartment);
            }


            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};