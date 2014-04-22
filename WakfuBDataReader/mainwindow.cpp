#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BinaryReader.h"
#include "BinaryReaders/BaseBinaryReader.h"
#include "BinaryReaders/BinaryReaderInclude.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->setSortingEnabled(true);

    m_binaryReader = NULL;
    m_file = QByteArray();
    m_fileId = 0;

    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(Open()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Open()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open file"), "", tr("Binary file (*.bin)"));

    if (filename.isNull())
        return;

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly))
        return;

    m_file = file.readAll();
    m_fileId = (quint8)QFileInfo(filename).fileName().split(".").at(0).toUInt();

    ui->statusBar->showMessage("Reading header file...");

    ReadHeader();
}

void MainWindow::ReadHeader()
{
    BinaryReader reader(m_file, m_fileId);
    int rows = reader.ReadInt();
    qDebug() << rows;

    for (int i = 0; i < rows; ++i)
    {
        Row row;
        row.id = reader.ReadLong();
        row.offset = reader.ReadInt();
        row.size = reader.ReadInt();
        row.unk = reader.ReadByte();

        m_rows.insert(i, row);
        /*qDebug() << "[" << i << "] "  << "id : " << row.id;
        qDebug() << "offset : " << row.offset;
        qDebug() << "size : " << row.size;
        qDebug() << "unk byte : " << row.unk;*/
    }

    qint8 blocks = reader.ReadByte();
    qDebug() << "Blocks : " << blocks;
    for (quint32 i = 0; i < blocks; ++i)
    {
        qint8 unk = reader.ReadByte();
        qDebug() << unk;

        qint32 strSize = reader.ReadInt();
        QByteArray buffer;
        buffer.resize(strSize);
        reader.ReadRawBytes(buffer.data(), buffer.size());

        QString index = QString(buffer);
        //qDebug() << index;

        qint32 rows = reader.ReadInt();
        for (qint32 k = 0; k < rows; ++k)
        {
            qint64 id = reader.ReadLong();

            if (unk == 0)
            {
                qint32 unkInt = reader.ReadInt();
                for (qint32 l = 0; l < unkInt; ++l)
                {
                    qint32 unkInt2 = reader.ReadInt();
                }
            }
            else
            {
                qint32 unkInt = reader.ReadInt();
            }
        }
    }

    ui->statusBar->showMessage("Reading data...");
    QByteArray buffer = reader.ReadAllFromCurrentPos();

    switch (m_fileId)
    {
    case 3:
        m_binaryReader = new AchievementCategory();
        break;
    case 8:
        m_binaryReader = new Boat();
        break;
    case 13:
        m_binaryReader = new CensoredEntry();
        break;
    case 23:
        m_binaryReader = new Craft();
        break;
    case 34:
        m_binaryReader = new InteractiveElementModel();
        break;
    case 37:
        m_binaryReader = new ItemType();
        break;
    case 47:
        m_binaryReader = new MonsterType();
        break;
    case 53:
        m_binaryReader = new NationRank();
        break;
    case 81:
        m_binaryReader = new Emote();
        break;
    case 128:
        m_binaryReader = new InteractiveElementTemplate();
        break;
    default:
        break;
    }

    if (!m_binaryReader)
    {
        ui->statusBar->showMessage("No BinaryReader found for file " + QString::number(m_fileId) + ".bin...");
        return;
    }

    m_binaryReader->Open(buffer, m_fileId, reader.GetSize());

    connect(m_binaryReader, SIGNAL(Finished(QVector<QVariantList>)), this, SLOT(UpdateTreeData(QVector<QVariantList>)));
    m_binaryReader->Read(m_rows);
}

void MainWindow::UpdateTreeData(QVector<QVariantList> data)
{
    ui->statusBar->showMessage("Loading " + QString::number(data.size()) + " rows...");

    QString columns = m_binaryReader->GetColumns();
    QStringList col = columns.split("|");
    col.prepend("#");

    ui->treeWidget->setColumnCount(col.size());
    ui->treeWidget->setHeaderLabels(col);

    for (quint16 i = 0; i < col.size(); ++i)
        ui->treeWidget->header()->resizeSection(i, 100);

    QList<QTreeWidgetItem*> items;

    for (quint32 i = 0; i < data.size(); ++i)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem;
        QVariantList d = data.at(i);

        item->setText(0, QString::number(i));

        for (quint32 j = 0; j < d.size(); ++j)
            item->setText(j + 1, d.at(j).toString());

        items.push_back(item);
    }

    ui->treeWidget->addTopLevelItems(items);
    ui->statusBar->showMessage("Data successfully loaded. " + QString::number(data.size()) + " entries.");
}
