#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QDir>
#include <QGridLayout>
#include <QInputDialog>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QWidget>

#include "cell.h"
#include "qfloodit.h"

class GameScene : public QWidget {
    Q_OBJECT
public:
    explicit GameScene(QFloodIt& qFloodIt, QWidget* parent = nullptr);

signals:
    void newGameConfirmation();
    void registerScoreConfirmation();

public slots:
    void initBoard();
    void updateBoard();
    void finalBoard();
    void newGame();
    void registerScore();

private:
    QFloodIt* model;
    QLabel* progressLbl;
    QWidget* boardWidget;
    QGridLayout* boardLayout;
    QPushButton* newGameBtn;
    QPushButton* registerScoreBtn;
    QVBoxLayout* mainLayout;

    void initComponents();
    void clearComponents();
    void arrangement();
    void behavior();
};

#endif // GAMESCENE_H
