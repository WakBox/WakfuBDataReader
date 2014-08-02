#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QTreeWidget>

struct Row
{
    long id;
    int offset;
    int size;
    qint8 unk;
};

typedef QMap<int, Row> Rows;

namespace Ui {
class MainWindow;
}
class BaseBinaryReader;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void ReadHeader();

public slots:
    void Open();
    void OnRowClicked(QTreeWidgetItem* row, int column);
    void UpdateTreeData(QVector<QVariantList> data);
    
private:
    Ui::MainWindow *ui;
    BaseBinaryReader* m_binaryReader;

    QByteArray m_file;
    quint8 m_fileId;

    Rows m_rows;

    QVector<QVariantList> m_data;
};

#endif // MAINWINDOW_H
