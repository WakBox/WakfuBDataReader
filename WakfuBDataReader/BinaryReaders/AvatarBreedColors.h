#include "BaseBinaryReader.h"

struct Color
{
    float m_red;
    float m_green;
    float m_blue;
    float m_alpha;
};

struct Data
{
    qint8 m_sex;
    qint8 m_defaultSkinIndex;
    qint8 m_defaultSkinFactor;
    qint8 m_defaultHairIndex;
    qint8 m_defaultHairFactor;
    qint8 m_defaultPupilIndex;
    QList<Color> m_skinColors;
    QList<Color> m_hairColors;
    QList<Color> m_pupilColors;
};

struct AvatarBreedColorsBinaryData
{
    qint32 m_id;
    QList<Data> m_values;
};

class AvatarBreedColors : public BaseBinaryReader
{
public:
    AvatarBreedColors() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            AvatarBreedColorsBinaryData entry;

            entry.m_id = r->ReadInt("m_id");

            qint32 valueCount = r->ReadInt();

            for (qint32 i = 0; i < valueCount; ++i)
            {
                Data data;

                data.m_sex = r->ReadByte();
                data.m_defaultSkinIndex = r->ReadByte();
                data.m_defaultSkinFactor = r->ReadByte();
                data.m_defaultHairIndex = r->ReadByte();
                data.m_defaultHairFactor = r->ReadByte();
                data.m_defaultPupilIndex = r->ReadByte();
                qint32 skinColorCount = r->ReadInt();

                for (qint32 j = 0; j < skinColorCount; ++j)
                {
                    Color color;

                    color.m_red = r->ReadFloat();
                    color.m_green = r->ReadFloat();
                    color.m_blue = r->ReadFloat();
                    color.m_alpha = r->ReadFloat();

                    data.m_skinColors.push_back(color);
                }
                    qint32 hairColorCount = r->ReadInt();

                    for (qint32 k = 0; k < hairColorCount; ++k)
                    {
                        Color color;

                        color.m_red = r->ReadFloat();
                        color.m_green = r->ReadFloat();
                        color.m_blue = r->ReadFloat();
                        color.m_alpha = r->ReadFloat();

                        data.m_hairColors.push_back(color);
                    }
                        qint32 pupilColorCount = r->ReadInt();

                        for (qint32 l = 0; l < pupilColorCount; ++l)
                        {
                            Color color;

                            color.m_red = r->ReadFloat();
                            color.m_green = r->ReadFloat();
                            color.m_blue = r->ReadFloat();
                            color.m_alpha = r->ReadFloat();

                            data.m_pupilColors.push_back(color);
                        }

                entry.m_values.push_back(data);
            }


            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};