#include "gamescene.h"

GameScene::GameScene(QFloodIt& qFloodIt, QWidget* parent)
    : QWidget(parent)
    , model(&qFloodIt)
{
    initComponents();
    arrangement();
    behavior();
}

void GameScene::initBoard()
{
    unsigned boardHeight = model->chosenHeight();
    unsigned boardWidth = model->chosenWidth();
}

void GameScene::updateBoard()
{
}

void GameScene::initComponents()
{
    boardLayout = new QGridLayout;
    boardLayout->setSpacing(0);
    boardWidget = new QWidget;
    mainLayout = new QVBoxLayout;
    mainLayout->setAlignment(Qt::AlignCenter);
    progressLbl = new QLabel("Number of moves : 0");
    progressLbl->setAlignment(Qt::AlignCenter);
}

void GameScene::arrangement()
{
    setLayout(mainLayout);
    boardWidget->setLayout(boardLayout);
    boardWidget->setObjectName("board");
    mainLayout->addWidget(boardWidget);
    mainLayout->addWidget(progressLbl);
    mainLayout->setSpacing(15);
}

void GameScene::behavior()
{
}
