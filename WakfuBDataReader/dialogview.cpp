#include "dialogview.h"
#include "ui_dialogview.h"

DialogView::DialogView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogView)
{
    ui->setupUi(this);
}

DialogView::~DialogView()
{
    delete ui;
}

void DialogView::SetData(QVector<Col> rows)
{
    QString result = QString();

    for (qint32 i = 0; i < rows.size(); ++i)
        result += (rows.at(i).name + " : " + rows.at(i).value.toString() + "\n");

    ui->plainTextEdit->appendPlainText(result);
}
