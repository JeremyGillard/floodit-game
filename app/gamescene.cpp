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
    newGameBtn->hide();
    registerScoreBtn->hide();
    clearComponents();
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

void GameScene::finalBoard()
{
    updateBoard();
    newGameBtn->show();
    registerScoreBtn->show();
}

void GameScene::newGame()
{
    if (!model->isOver()) {
        int response = QMessageBox::question(this, "New game confirm?",
            "Are you sure you want to start a new game without having finished the current one?",
            QMessageBox ::Yes | QMessageBox::No);
        if (response == QMessageBox::Yes) {
            emit newGameConfirmation();
        }
    } else {
        emit newGameConfirmation();
    }
}

void GameScene::registerScore()
{
    if (!model->isOver()) {
        QMessageBox msgBox;
        msgBox.setText("You must have finished the party to be able to register");
        msgBox.exec();
    } else {
        bool ok;
        QString text = QInputDialog::getText(this, "Pseudo", "Please enter your pseudo:", QLineEdit::Normal, QDir::home().dirName(), &ok);
        if (ok && !text.isEmpty()) {
            model->newScore(text.toUtf8().constData());
            emit registerScoreConfirmation();
        }
    }
}

void GameScene::initComponents()
{
    boardLayout = new QGridLayout;
    boardLayout->setSpacing(0);
    boardWidget = new QWidget(this);
    mainLayout = new QVBoxLayout;
    mainLayout->setAlignment(Qt::AlignCenter);
    progressLbl = new QLabel("Number of moves : 0");
    progressLbl->setAlignment(Qt::AlignCenter);
    newGameBtn = new QPushButton("New Game", this);
    registerScoreBtn = new QPushButton("Register Score", this);
}

void GameScene::clearComponents()
{
    progressLbl->setText("Number of moves : 0");
    QLayoutItem* child;
    while ((child = boardLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
}

void GameScene::arrangement()
{
    setLayout(mainLayout);
    boardWidget->setLayout(boardLayout);
    boardWidget->setObjectName("board");
    mainLayout->addWidget(boardWidget);
    mainLayout->addWidget(progressLbl);
    mainLayout->addWidget(newGameBtn);
    mainLayout->addWidget(registerScoreBtn);
    mainLayout->setSpacing(15);
}

void GameScene::behavior()
{
    connect(model, &QFloodIt::boardChanged, this, &GameScene::updateBoard);
    connect(newGameBtn, &QPushButton::clicked, this, &GameScene::newGame);
    connect(registerScoreBtn, &QPushButton::clicked, this, &GameScene::registerScore);
}
