#ifndef CELL_H
#define CELL_H

#include <QPainter>
#include <QPushButton>
#include <QWidget>

#include "qfloodit.h"

class Cell : public QPushButton {
    Q_OBJECT
public:
    explicit Cell(const QString& text, unsigned i, unsigned j, QFloodIt& qFloodIt, QWidget* parent = nullptr);

private:
    QFloodIt* model;

    unsigned i;

    unsigned j;

    void arrangement();

    void behavior();
};

#endif // CELL_H
