#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , switchSceneIndex(0)
{
    initComponents();
    arrangement();
    behavior();
}

MainWindow::~MainWindow()
{
}

void MainWindow::switchScene()
{
    if (switchSceneIndex) {
        switchSceneIndex = 0;
    } else {
        ++switchSceneIndex;
    }
    layout->setCurrentIndex(switchSceneIndex);
}

void MainWindow::initComponents()
{
    setWindowTitle("Flood It");
    setFixedSize(500, 600);
    model = new QFloodIt(this);
    centralWidget = new QWidget(this);
    layout = new QStackedLayout;
    iScene = new IntroductionScene(*model, this);
    gScene = new GameScene(*model, this);
}

void MainWindow::arrangement()
{
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    layout->addWidget(iScene);
    layout->addWidget(gScene);
}

void MainWindow::behavior()
{
    connect(iScene, &IntroductionScene::gameIsInitialized, this, &MainWindow::switchScene);
    connect(iScene, &IntroductionScene::gameIsInitialized, gScene, &GameScene::initBoard);
    connect(model, &QFloodIt::gameFinished, gScene, &GameScene::finalBoard);
    connect(gScene, &GameScene::newGameConfirmation, this, &MainWindow::switchScene);
}
