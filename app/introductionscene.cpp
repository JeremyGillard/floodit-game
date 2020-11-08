#include "introductionscene.h"

IntroductionScene::IntroductionScene(QWidget* parent)
    : QWidget(parent)
{
    initComponents();
    arrangement();
    behavior();
}

void IntroductionScene::initComponents()
{
    title = new QLabel("Flood It");
    boardHeightLbl = new QLabel("Board height");
    boardHeightCbb = new QComboBox;
    boardWidthLbl = new QLabel("Board width");
    boardWidthCbb = new QComboBox;
    for (unsigned i = 5; i < 21; ++i) {
        boardHeightCbb->addItem(QString::number(i), i);
        boardWidthCbb->addItem(QString::number(i), i);
    }
    difficultyLbl = new QLabel("Number of color");
    difficultyCbb = new QComboBox;
    for (unsigned i = 3; i < 9; ++i) {
        difficultyCbb->addItem(QString::number(i), i);
    }
    startBtn = new QPushButton("Start");
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
}
