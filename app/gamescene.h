#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

#include "qfloodit.h"

class GameScene : public QWidget {
    Q_OBJECT
public:
    explicit GameScene(QFloodIt& qFloodIt, QWidget* parent = nullptr);

public slots:
    void initBoard();
    void updateBoard();

private:
    QFloodIt* model;
    QLabel* progressLbl;
    QWidget* boardWidget;
    QGridLayout* boardLayout;
    QVBoxLayout* mainLayout;

    void initComponents();
    void arrangement();
    void behavior();
};

#endif // GAMESCENE_H
