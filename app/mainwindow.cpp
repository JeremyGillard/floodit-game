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
    layout->setCurrentIndex(switchSceneIndex);
    if (switchSceneIndex > 1) {
        switchSceneIndex = 0;
    } else {
        ++switchSceneIndex;
    }
}

void MainWindow::initComponents()
{
    setWindowTitle("Flood It");
    setFixedSize(500, 600);
    centralWidget = new QWidget(this);
    layout = new QStackedLayout;
    iScene = new IntroductionScene(this);
    gScene = new GameScene(this);
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
}
