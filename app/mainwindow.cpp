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
        menuBar()->show();
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
    qApp->setStyle(QStyleFactory::keys().at(2));
    initMenuBar();
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
    connect(actionNewGame, &QAction::triggered, gScene, &GameScene::newGame);
    connect(actionQuit, &QAction::triggered, qApp, &QApplication::quit);
}

void MainWindow::initMenuBar()
{
    QMenu* menuTaquin = menuBar()->addMenu("Flood It");
    actionNewGame = new QAction("New Game", this);
    actionQuit = new QAction("Quit", this);
    menuTaquin->addAction(actionNewGame);
    menuTaquin->addAction(actionQuit);
    menuBar()->hide();
}
