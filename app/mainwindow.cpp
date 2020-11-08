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

void MainWindow::setIntroScene()
{
    menuBar()->hide();
    layout->setCurrentIndex(0);
}

void MainWindow::setGameScene()
{
    menuBar()->show();
    layout->setCurrentIndex(1);
}

void MainWindow::setScoreScene()
{
    menuBar()->show();
    layout->setCurrentIndex(2);
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
    sScene = new ScoreScene(*model, this);
    qApp->setStyle(QStyleFactory::keys().at(2));
    initMenuBar();
}

void MainWindow::arrangement()
{
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    layout->addWidget(iScene);
    layout->addWidget(gScene);
    layout->addWidget(sScene);
}

void MainWindow::behavior()
{
    connect(iScene, &IntroductionScene::gameIsInitialized, this, &MainWindow::setGameScene);
    connect(iScene, &IntroductionScene::gameIsInitialized, gScene, &GameScene::initBoard);
    connect(model, &QFloodIt::gameFinished, gScene, &GameScene::finalBoard);
    connect(gScene, &GameScene::newGameConfirmation, this, &MainWindow::setIntroScene);
    connect(gScene, &GameScene::registerScoreConfirmation, this, &MainWindow::setScoreScene);
    connect(gScene, &GameScene::registerScoreConfirmation, sScene, &ScoreScene::populateData);
    connect(gScene, &GameScene::registerScoreConfirmation, this, &MainWindow::setScoreScene);
    connect(sScene, &ScoreScene::newGame, this, &MainWindow::setIntroScene);
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
