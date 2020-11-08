#ifndef SCORESCENE_H
#define SCORESCENE_H

#include <QHeaderView>
#include <QLabel>
#include <QPushButton>
#include <QStringListModel>
#include <QTableView>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QWidget>

#include "qfloodit.h"

class ScoreScene : public QWidget {
    Q_OBJECT
public:
    explicit ScoreScene(QFloodIt& qFloodIt, QWidget* parent = nullptr);

signals:
    void newGame();

public slots:
    void populateData();

private:
    QFloodIt* model;

    QLabel* sceneTitle;

    QTableWidget* table;

    QPushButton* newGameBtn;

    QVBoxLayout* mainLayout;

    void initComponents();
    void arrangement();
    void behavior();
};

#endif // SCORESCENE_H
