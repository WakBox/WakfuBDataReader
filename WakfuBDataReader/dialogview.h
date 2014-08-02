#ifndef DIALOGVIEW_H
#define DIALOGVIEW_H

#include <QDialog>
#include <QVariantList>

#include "BinaryReader.h"

namespace Ui {
class DialogView;
}

class DialogView : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogView(QWidget *parent = 0);
    ~DialogView();

    void SetData(QVector<Col> rows);
    
private:
    Ui::DialogView *ui;
};

#endif // DIALOGVIEW_H
