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
    case 1:
        m_binaryReader = new Achievement();
        break;
    case 2:
        m_binaryReader = new AchievementVariable();
        break;
    case 3:
        m_binaryReader = new AchievementCategory();
        break;
    case 4:
        m_binaryReader = new AreaEffect();
        break;
    case 5:
        m_binaryReader = new AudioMarkerInteractiveElementParam();
        break;
    case 6:
        m_binaryReader = new BackgroundFeedback();
        break;
    case 7:
        m_binaryReader = new BackgroundInteractiveElementParam();
        break;
    case 8:
        m_binaryReader = new Boat();
        break;
    case 9:
        m_binaryReader = new BoatLink();
        break;
    case 10:
        // ??
        break;
    case 11:
        // ??
        break;
    case 12:
        m_binaryReader = new Cannon();
        break;
    case 13:
        m_binaryReader = new CensoredEntry();
        break;
    case 14: // not sure
        m_binaryReader = new ChaosParam();
        break;
    case 15:
        // ??
        break;
    case 16:
        m_binaryReader = new CharacGainPerLevel();
        break;
    case 17:
        m_binaryReader = new CitizenRank();
        break;
    case 18:
        m_binaryReader = new ClientEvent();
        break;
    case 19:
        // ??
        break;
    case 20:
        m_binaryReader = new ClimateBonus();
        break;
    case 21:
        m_binaryReader = new ClimateBonusList();
        break;
    case 22:
        m_binaryReader = new CollectInteractiveElementParam();
        break;
    case 23:
        m_binaryReader = new Craft();
        break;
    case 24:
        m_binaryReader = new CraftInteractiveElementParam();
        break;
    case 25:
        m_binaryReader = new DecorationInteractiveElementParam();
        break;
    case 26:
        m_binaryReader = new DestructibleElementParam();
        break;
    case 27:
        m_binaryReader = new Dialog();
        break;
    case 28:
        m_binaryReader = new Drago();
        break;
    case 29:
        m_binaryReader = new EffectGroup();
        break;
    case 30:
        m_binaryReader = new GemBackgroundInteractiveElementParam();
        break;
    case 31:
        m_binaryReader = new GenericActivableInteractiveElementParam();
        break;
    case 32:
        m_binaryReader = new Ground();
        break;
    case 33:
        m_binaryReader = new HavenBagModelView();
        break;
    case 34:
        m_binaryReader = new InteractiveElementModel();
        break;
    case 35:
        m_binaryReader = new Item();
        break;
    case 36:
        m_binaryReader = new ItemSet();
        break;
    case 37:
        m_binaryReader = new ItemType();
        break;
    case 38:
        m_binaryReader = new LootChestInteractiveElementParam();
        break;
    case 39:
        // ??
        break;
    case 40:
        // ??
        break;
    case 41:
        m_binaryReader = new MarketBoardInteractiveElementParam();
        break;
    case 42:
        m_binaryReader = new Monster();
        break;
    case 43:
        // ?
        break;
    case 44:
        // ?
        break;
    case 45:
        // ?
        break;
    case 46:
        // ?
        break;
    case 47:
        m_binaryReader = new MonsterType();
        break;
    case 48:
        m_binaryReader = new MonsterTypePest();
        break;
    case 49:
        m_binaryReader = new MonsterTypeRelashionship();
        break;
    case 50:
        // ?
        break;
    case 51:
        m_binaryReader = new NationColors();
        break;
    case 52:
        m_binaryReader = new NationLaw();
        break;
    case 53:
        m_binaryReader = new NationRank();
        break;
    case 54:
        m_binaryReader = new Protector();
        break;
    case 55:
        m_binaryReader = new ProtectorBuff();
        break;
    case 56:
        m_binaryReader = new ProtectorBuffList();
        break;
    case 57:
        m_binaryReader = new ProtectorEcosystemProtection();
        break;
    case 58:
        m_binaryReader = new Recipe();
        break;
    case 59:
        // ?
        break;
    case 60:
        // ?
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
