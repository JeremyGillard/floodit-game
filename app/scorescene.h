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

/**
 * @brief The ScoreScene class allows to display the end score table.
 */
class ScoreScene : public QWidget {
    Q_OBJECT
public:
    /**
     * @brief ScoreScene allows to construct the end score table.
     *
     * @param qFloodIt the floodit that will be represented.
     * @param parent parent who will be in charge of its destruction.
     */
    explicit ScoreScene(QFloodIt& qFloodIt, QWidget* parent = nullptr);

signals:
    /**
     * @brief newGame signal when a player decides to start
     * a new game without having finished the previous one.
     */
    void newGame();

public slots:
    /**
     * @brief populateData allows to populate the score data in the final
     * score panel when the user switch to the final score scene.
     */
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
