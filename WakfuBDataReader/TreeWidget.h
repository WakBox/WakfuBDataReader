#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QTreeWidgetItem>

class TreeWidgetItem : public QTreeWidgetItem
{
public:
    TreeWidgetItem(QTreeWidget *tree) : QTreeWidgetItem(tree) {}
    TreeWidgetItem(QTreeWidget * parent, const QStringList & strings)
                   : QTreeWidgetItem (parent,strings)  {}

    bool operator< (const QTreeWidgetItem &other) const
    {
        int sortCol = treeWidget()->sortColumn();
        int myNumber = text(sortCol).toInt();
        int otherNumber = other.text(sortCol).toInt();
        return myNumber < otherNumber;
    }
};


#endif // TREEWIDGET_H
