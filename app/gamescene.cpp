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
    for (unsigned i = 0; i < boardHeight; ++i) {
        for (unsigned j = 0; j < boardWidth; ++j) {
            unsigned cellColor = model->getColorAt(i, j);
            boardLayout->addWidget(new Cell(cellColor, *model, boardWidget), i, j);
        }
    }
}

void GameScene::updateBoard()
{
    unsigned boardHeight = model->chosenHeight();
    unsigned boardWidth = model->chosenWidth();
    for (unsigned i = 0; i < boardHeight; ++i) {
        for (unsigned j = 0; j < boardWidth; ++j) {
            Cell* cell = qobject_cast<Cell*>(boardLayout->itemAtPosition(i, j)->widget());
            cell->changeColor(model->getColorAt(i, j));
        }
    }
    progressLbl->setText("Number of moves : " + QString::number(model->getNumberOfMoves()));
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
    connect(model, &QFloodIt::boardChanged, this, &GameScene::updateBoard);
}
