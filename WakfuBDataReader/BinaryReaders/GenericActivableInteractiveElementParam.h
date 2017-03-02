#include "BaseBinaryReader.h"

struct Action
{
    qint32 m_actionId;
    qint32 m_actionTypeId;
    QString m_criteria;
    QList<QString> m_actionParams;
};

struct GroupAction
{
    qint32 m_id;
    QString m_criteria;
    float m_weight;
    QList<Action> m_actions;
};

struct Visual
{
    qint32 m_id;
    qint32 m_visualId;
    qint32 m_itemConsumed;
    qint32 m_itemQuantity;
    bool m_doConsumeItem;
    qint32 m_kamaCost;
    qint32 m_distributionDuration;
    QList<GroupAction> m_groupActions;
};

struct GenericActivableInteractiveElementParamBinaryData
{
    qint32 m_id;
    QList<Visual> m_visuals;
    ChaosParamBinaryData m_chaosParams;
};

class GenericActivableInteractiveElementParam : public BaseBinaryReader
{
public:
    GenericActivableInteractiveElementParam() {}

    void Read(Rows rows)
    {
        qint32 size = rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = rows[i];
            r->SetBufferPosition(row.offset);

            GenericActivableInteractiveElementParamBinaryData entry;

            entry.m_id = r->ReadInt("m_id");

            qint32 visualCount = r->ReadInt();

            for (qint32 i = 0; i < visualCount; ++i)
            {
                Visual visual;

                visual.m_id = r->ReadInt();
                visual.m_visualId = r->ReadInt();
                visual.m_itemConsumed = r->ReadInt();
                visual.m_itemQuantity = r->ReadInt();
                visual.m_doConsumeItem = r->ReadBool();
                visual.m_kamaCost = r->ReadInt();
                visual.m_distributionDuration = r->ReadInt();
                qint32 groupActionCount = r->ReadInt();

                for (qint32 j = 0; j < groupActionCount; ++j)
                {
                    GroupAction groupAction;

                    groupAction.m_id = r->ReadInt();
                    groupAction.m_criteria = r->ReadString();
                    groupAction.m_weight = r->ReadFloat();
                    qint32 actionCount = r->ReadInt();

                    for (qint32 k = 0; k < actionCount; ++k)
                    {
                        Action action;

                        action.m_actionId = r->ReadInt();
                        action.m_actionTypeId = r->ReadInt();
                        action.m_criteria = r->ReadString();
                        action.m_actionParams = r->ReadStringArray();

                        groupAction.m_actions.push_back(action);
                    }

                    visual.m_groupActions.push_back(groupAction);
                }

                entry.m_visuals.push_back(visual);
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
