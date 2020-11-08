#ifndef INTRODUCTIONSCENE_H
#define INTRODUCTIONSCENE_H

#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "qfloodit.h"

class IntroductionScene : public QWidget {
    Q_OBJECT
public:
    explicit IntroductionScene(QFloodIt& qFloodIt, QWidget* parent = nullptr);

signals:
    void gameIsInitialized();

public slots:
    void initGame();

private:
    QFloodIt* model;

    QLabel* title;
    QLabel* boardHeightLbl;
    QComboBox* boardHeightCbb;
    QLabel* boardWidthLbl;
    QComboBox* boardWidthCbb;
    QLabel* difficultyLbl;
    QComboBox* difficultyCbb;
    QPushButton* startBtn;

    QGridLayout* userInformationLayout;
    QVBoxLayout* mainLayout;

    void initComponents();

    void initUserInformationLayout();

    void arrangement();

    void behavior();
};

#endif // INTRODUCTIONSCENE_H
