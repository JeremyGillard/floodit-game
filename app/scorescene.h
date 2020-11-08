#ifndef SCORESCENE_H
#define SCORESCENE_H

#include <QWidget>

#include "qfloodit.h"

class ScoreScene : public QWidget {
    Q_OBJECT
public:
    explicit ScoreScene(QFloodIt& qFloodIt, QWidget* parent = nullptr);

private:
    QFloodIt* model;
    void initComponents();
    void clearComponents();
    void arrangement();
    void behavior();
};

#endif // SCORESCENE_H
