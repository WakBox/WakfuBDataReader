#include "BaseBinaryReader.h"

struct RecipeIngredient
{
    qint32 m_itemId;
    qint16 m_quantity;
};

struct RecipeProduct
{
    qint32 m_itemId;
    qint16 m_quantity;
};

struct RecipeMaterial
{
    qint16 m_minLevel;
    qint16 m_minRarity;
    bool m_optionnal;
    QList<qint32> m_materialTypes;
};

struct RecipeBinaryData
{
    qint32 m_id;
    qint32 m_categoryId;
    qint64 m_duration;
    QString m_criteria;
    QString m_visibilityCriteria;
    qint32 m_level;
    QList<qint32> m_properties;
    qint32 m_xpRatio;
    QList<qint32> m_machinesUsingRecipe;
    qint32 m_successRate;
    bool m_contractEnabled;
    qint64 m_neededKamas;
    qint64 m_xp;
    QList<RecipeIngredient> m_ingredients;
    QList<RecipeProduct> m_products;
    QList<RecipeMaterial> m_materials;
};

class Recipe : public BaseBinaryReader
{
public:
    Recipe() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            RecipeBinaryData entry;

            entry.m_id = r->ReadInt("m_id");
            entry.m_categoryId = r->ReadInt("m_categoryId");
            entry.m_duration = r->ReadLong("m_duration");
            entry.m_criteria = r->ReadString("m_criteria");
            entry.m_visibilityCriteria = r->ReadString("m_visibilityCriteria");
            entry.m_level = r->ReadInt("m_level");
            entry.m_properties = r->ReadIntArray("m_properties");
            entry.m_xpRatio = r->ReadInt("m_xpRatio");
            entry.m_machinesUsingRecipe = r->ReadIntArray("m_machinesUsingRecipe");
            entry.m_successRate = r->ReadInt("m_successRate");
            entry.m_contractEnabled = r->ReadBool("m_contractEnabled");
            entry.m_neededKamas = r->ReadLong("m_neededKamas");
            entry.m_xp = r->ReadLong("m_xp");

            qint32 ingredientCount = r->ReadInt();

            for (qint32 i = 0; i < ingredientCount; ++i)
            {
                RecipeIngredient recipeIngredient;

                recipeIngredient.m_itemId = r->ReadInt();
                recipeIngredient.m_quantity = r->ReadShort();

                entry.m_ingredients.push_back(recipeIngredient);
            }


            qint32 productCount = r->ReadInt();

            for (qint32 i = 0; i < productCount; ++i)
            {
                RecipeProduct recipeProduct;

                recipeProduct.m_itemId = r->ReadInt();
                recipeProduct.m_quantity = r->ReadShort();

                entry.m_products.push_back(recipeProduct);
            }


            qint32 materialCount = r->ReadInt();

            for (qint32 i = 0; i < materialCount; ++i)
            {
                RecipeMaterial recipeMaterial;

                recipeMaterial.m_minLevel = r->ReadShort();
                recipeMaterial.m_minRarity = r->ReadShort();
                recipeMaterial.m_optionnal = r->ReadBool();
                recipeMaterial.m_materialTypes = r->ReadIntArray();

                entry.m_materials.push_back(recipeMaterial);
            }


            r->PushRow();
        }

        emit Finished(r->GetCols(), r->GetRows());
    }
};