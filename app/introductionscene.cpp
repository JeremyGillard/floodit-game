#include "introductionscene.h"

IntroductionScene::IntroductionScene(QFloodIt& qFloodIt, QWidget* parent)
    : QWidget(parent)
    , model(&qFloodIt)
{
    initComponents();
    arrangement();
    behavior();
}

void IntroductionScene::initGame()
{
    model->initBoard(boardHeightCbb->currentData().toUInt(), boardWidthCbb->currentData().toUInt());
    model->setDifficulty(difficultyCbb->currentData().toUInt());
    emit gameIsInitialized();
}

void IntroductionScene::initComponents()
{
    title = new QLabel("Flood It", this);
    boardHeightLbl = new QLabel("Board height", this);
    boardHeightCbb = new QComboBox(this);
    boardWidthLbl = new QLabel("Board width", this);
    boardWidthCbb = new QComboBox(this);
    for (unsigned i = 5; i < 21; ++i) {
        boardHeightCbb->addItem(QString::number(i), i);
        boardWidthCbb->addItem(QString::number(i), i);
    }
    difficultyLbl = new QLabel("Number of color", this);
    difficultyCbb = new QComboBox(this);
    for (unsigned i = 3; i < 9; ++i) {
        difficultyCbb->addItem(QString::number(i), i);
    }
    startBtn = new QPushButton("Start", this);
    userInformationLayout = new QGridLayout;
    mainLayout = new QVBoxLayout;
}

void IntroductionScene::initUserInformationLayout()
{
    userInformationLayout->addWidget(boardHeightLbl, 0, 0);
    userInformationLayout->addWidget(boardHeightCbb, 0, 1);
    userInformationLayout->addWidget(boardWidthLbl, 1, 0);
    userInformationLayout->addWidget(boardWidthCbb, 1, 1);
    userInformationLayout->addWidget(difficultyLbl, 2, 0);
    userInformationLayout->addWidget(difficultyCbb, 2, 1);
}

void IntroductionScene::arrangement()
{
    initUserInformationLayout();
    mainLayout->addWidget(title);
    mainLayout->addLayout(userInformationLayout);
    mainLayout->addWidget(startBtn);
    mainLayout->setAlignment(Qt::AlignCenter);
    mainLayout->setSpacing(20);
    setLayout(mainLayout);
}

void IntroductionScene::behavior()
{
    connect(startBtn, &QPushButton::clicked, this, &IntroductionScene::initGame);
}
