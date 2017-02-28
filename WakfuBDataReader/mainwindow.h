#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDropEvent>
#include <QMimeData>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QTreeWidget>

#include "BinaryReader.h"

struct Row
{
    qint64 id;
    qint32 offset;
    qint32 size;
    qint8 seed;
};

typedef QMap<int, Row> Rows;

namespace Ui {
class MainWindow;
}

class BinaryReader;
class BaseBinaryReader;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void OpenFile(QString filename);
    void ReadHeader();

public slots:
    void Open();
    void UpdateTreeData(Entry cols, DataRow rows);

protected:
    void dragEnterEvent(QDragEnterEvent *e);
    void dropEvent(QDropEvent *e);
    
private:
    Ui::MainWindow *ui;
    BaseBinaryReader* m_binaryReader;

    QByteArray m_file;
    quint8 m_fileId;

    Rows m_rows;
};

#endif // MAINWINDOW_H
