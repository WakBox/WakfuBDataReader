#include "BaseBinaryReader.h"

struct AvatarBreedBinaryData
{
    qint32 m_id;
    QString m_name;
    qint32 m_backgroundAps;
    qint32 m_baseHp;
    qint32 m_baseAp;
    qint32 m_baseMp;
    qint32 m_baseWp;
    qint32 m_baseInit;
    qint32 m_baseFerocity;
    qint32 m_baseFumble;
    qint32 m_baseWisdom;
    qint32 m_baseTackle;
    qint32 m_baseDodge;
    qint32 m_baseProspection;
    qint32 m_timerCountBeforeDeath;
    qint32 m_preferedArea;
    QList<qint8> m_spellElements;
    QList<float> m_characRatios;
};

class AvatarBreed : public BaseBinaryReader
{
public:
    AvatarBreed() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            AvatarBreedBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_name = r->ReadString("m_name");
            entry.m_backgroundAps = r->ReadInt("m_backgroundAps");
            entry.m_baseHp = r->ReadInt("m_baseHp");
            entry.m_baseAp = r->ReadInt("m_baseAp");
            entry.m_baseMp = r->ReadInt("m_baseMp");
            entry.m_baseWp = r->ReadInt("m_baseWp");
            entry.m_baseInit = r->ReadInt("m_baseInit");
            entry.m_baseFerocity = r->ReadInt("m_baseFerocity");
            entry.m_baseFumble = r->ReadInt("m_baseFumble");
            entry.m_baseWisdom = r->ReadInt("m_baseWisdom");
            entry.m_baseTackle = r->ReadInt("m_baseTackle");
            entry.m_baseDodge = r->ReadInt("m_baseDodge");
            entry.m_baseProspection = r->ReadInt("m_baseProspection");
            entry.m_timerCountBeforeDeath = r->ReadInt("m_timerCountBeforeDeath");
            entry.m_preferedArea = r->ReadInt("m_preferedArea");
            entry.m_spellElements = r->ReadByteArray("m_spellElements");
            entry.m_characRatios = r->ReadFloatArray("m_characRatios");

            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};