#include "BaseBinaryReader.h"

struct Consumable
{
    qint32 m_itemId;
    qint16 m_quantity;
};

struct Resulting
{
    qint32 m_itemId;
    qint16 m_quantity;
    qint8 m_forcedBindType;
};

struct Exchange
{
    qint32 m_exchangeId;
    QString m_criteria;
    QList<Consumable> m_consumables;
    qint32 m_consumableKama;
    qint32 m_consumablePvpMoney;
    QList<Resulting> m_resultings;
    qint32 m_resultingKama;
};

struct ExchangeInteractiveElementParamBinaryData
{
    qint32 m_id;
    qint32 m_apsId;
    qint32 m_visualMruId;
    qint8 m_sortTypeId;
    QList<Exchange> m_exchanges;
    ChaosParamBinaryData m_chaosParams;
};

class ExchangeInteractiveElementParam : public BaseBinaryReader
{
public:
    ExchangeInteractiveElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            ExchangeInteractiveElementParamBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_apsId = r->ReadInt("m_apsId");
            entry.m_visualMruId = r->ReadInt("m_visualMruId");
            entry.m_sortTypeId = r->ReadByte("m_sortTypeId");

            qint32 exchangeCount = r->ReadInt();

            for (qint32 i = 0; i < exchangeCount; ++i)
            {
                Exchange exchange;

                exchange.m_exchangeId = r->ReadInt();
                exchange.m_criteria = r->ReadString();

                qint32 consumableCount = r->ReadInt();

                for (qint32 j = 0; j < consumableCount; ++j)
                {
                    Consumable consumable;

                    consumable.m_itemId = r->ReadInt();
                    consumable.m_quantity = r->ReadShort();

                    exchange.m_consumables.push_back(consumable);
                }

                exchange.m_consumableKama = r->ReadInt();
                exchange.m_consumablePvpMoney = r->ReadInt();

                qint32 resultingCount = r->ReadInt();

                for (qint32 k = 0; k < resultingCount; ++k)
                {
                    Resulting resulting;

                    resulting.m_itemId = r->ReadInt();
                    resulting.m_quantity = r->ReadShort();
                    resulting.m_forcedBindType = r->ReadByte();

                    exchange.m_resultings.push_back(resulting);
                }

                exchange.m_resultingKama = r->ReadInt();
                entry.m_exchanges.push_back(exchange);
            }

            qint8 hasChaosParam = r->ReadByte("hasChaosParams");
            if (hasChaosParam != 0)
            {
                entry.m_chaosParams.m_chaosLevel = r->ReadByte("m_chaosLevel");
                entry.m_chaosParams.m_chaosCollectorParamId = r->ReadInt("m_chaosCollectorParamId");
            }

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};
