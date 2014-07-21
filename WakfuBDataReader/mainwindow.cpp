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
    // Clean first
    if (m_binaryReader)
    {
        delete m_binaryReader;
        m_binaryReader = NULL;

        ui->treeWidget->clear();
    }

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
        m_binaryReader = new Resource();
        break;
    case 61:
        // ?
        break;
    case 62:
        // ?
        break;
    case 63:
        // ?
        break;
    case 64:
        m_binaryReader = new Skill();
        break;
    case 65:
        m_binaryReader = new SkillAction();
        break;
    case 66:
        m_binaryReader = new Spell();
        break;
    case 67:
        m_binaryReader = new State();
        break;
    case 68:
        m_binaryReader = new StaticEffect();
        break;
    case 69:
        m_binaryReader = new StoolInteractiveElementParam();
        break;
    case 70:
        m_binaryReader = new StorageBox();
        break;
    case 71:
        m_binaryReader = new StreetLightInteractiveElementParam();
        break;
    case 72:
        m_binaryReader = new Teleporter();
        break;
    case 73:
        m_binaryReader = new TimelineBuffList();
        break;
    case 74:
        // ?
        break;
    case 75:
        // ?
        break;
    case 76:
        m_binaryReader = new Zaap();
        break;
    case 77:
        m_binaryReader = new ZaapLink();
        break;
    case 78:
        m_binaryReader = new Aptitude();
        break;
    case 79:
        m_binaryReader = new BoardInteractiveElementParam();
        break;
    case 80:
        m_binaryReader = new ChallengeLootList();
        break;
    case 81:
        m_binaryReader = new Emote();
        break;
    case 82:
        m_binaryReader = new ExchangeInteractiveElementParam();
        break;
    case 83:
        // ?
        break;
    case 84:
        // ?
        break;
    case 85:
        m_binaryReader = new RecycleMachineInteractiveElementParam();
        break;
    case 86:
        m_binaryReader = new AvatarBreed();
        break;
    case 87:
        m_binaryReader = new ArcadeDungeon();
        break;
    case 88:
        // ?
        break;
    case 89:
        break;
    case 90:
        m_binaryReader = new ArcadeChallenge();
        break;
    case 91:
        break;
    case 92:
        break;
    case 93:
        break;
    case 94:
        break;
    case 95:
        m_binaryReader = new DungeonDisplayerInteractiveElementParam();
        break;
    case 96:
        m_binaryReader = new RewardDisplayerInteractiveElementParam();
        break;
    case 97:
        m_binaryReader = new HavenWorldBuilding();
        break;
    case 98:
        m_binaryReader = new AlmanachEntry();
        break;
    case 99:
        m_binaryReader = new AlmanachDate();
        break;
    case 100:
        m_binaryReader = new HavenWorldDefinition();
        break;
    case 101:
        m_binaryReader = new HavenWorldPatchDefinition();
        break;
    case 102:
        break;
    case 103:
        m_binaryReader = new HavenWorldBuildingEvolution();
        break;
    case 104:
        m_binaryReader = new HavenWorldBuildingCatalog();
        break;
    case 105:
        m_binaryReader = new BookcaseInteractiveElementParam();
        break;
    case 106:
        m_binaryReader = new EquipableDummyInteractiveElementParam();
        break;
    case 107:
        m_binaryReader = new HavenWorldBuildingVisualDefinition();
        break;
    case 108:
        m_binaryReader = new KrosmozGameBoardInteractiveElementParam();
        break;
    case 109:
        m_binaryReader = new KrosmozGameCollectionInteractiveElementParam();
        break;
    case 110:
        break;
    case 111:
        m_binaryReader = new HavenWorldBoardInteractiveElementParam();
        break;
    case 112:
        break;
    case 113:
        m_binaryReader = new KrosmozFigure();
        break;
    case 114:
        m_binaryReader = new LightLootList();
        break;
    case 115:
        m_binaryReader = new AchievementList();
        break;
    case 116:
        m_binaryReader = new AvatarBreedColors();
        break;
    case 117:
        m_binaryReader = new Pet();
        break;
    case 118:
        m_binaryReader = new DoorInteractiveElementParam();
        break;
    case 119:
        m_binaryReader = new Dungeon();
        break;
    case 120:
        m_binaryReader = new Lock();
        break;
    case 121:
        m_binaryReader = new Bags();
        break;
    case 122:
        m_binaryReader = new Treasure();
        break;
    case 123:
        m_binaryReader = new MagiCraftLootList();
        break;
    case 124:
        m_binaryReader = new GemAndPowder();
        break;
    case 125:
        break;
    case 126:
        m_binaryReader = new HavenWorldBuildingDeco();
        break;
    case 127:
        break;
    case 128:
        m_binaryReader = new InteractiveElementTemplate();
        break;
    case 129:
        m_binaryReader = new Tutorial();
        break;
    case 130:
        m_binaryReader = new FightChallenge();
        break;
    case 131:
        m_binaryReader = new CompanionItem();
        break;
    case 132:
        m_binaryReader = new FightChallengeMonster();
        break;
    case 133:
        m_binaryReader = new Secret();
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

    connect(m_binaryReader, SIGNAL(Finished(Entry, DataRow)), this, SLOT(UpdateTreeData(Entry, DataRow)));
    m_binaryReader->Read(m_rows);
}

void MainWindow::UpdateTreeData(Entry cols, DataRow rows)
{
    ui->statusBar->showMessage("Loading " + QString::number(rows.size()) + " rows...");

    QStringList labels;
    for (Entry::ConstIterator itr = cols.begin(); itr != cols.end(); ++itr)
        labels << (*itr).name;

    labels.prepend("#");
    ui->treeWidget->setColumnCount(labels.size());
    ui->treeWidget->setHeaderLabels(labels);

    for (quint16 i = 0; i < labels.size(); ++i)
        ui->treeWidget->header()->resizeSection(i, 100);

    QList<QTreeWidgetItem*> items;
    for (quint32 i = 0; i < rows.size(); ++i)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem;
        Entry d = rows.at(i);
        int index = 0;

        item->setText(index++, QString::number(i));

        for (Entry::ConstIterator itr = d.begin(); itr != d.end(); ++itr)
            item->setText(index++, (*itr).value.toString());

        items.push_back(item);
    }

    ui->treeWidget->addTopLevelItems(items);
    ui->statusBar->showMessage("Data successfully loaded. " + QString::number(rows.size()) + " entries.");
}
