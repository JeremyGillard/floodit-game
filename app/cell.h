#ifndef CELL_H
#define CELL_H

#include <QPainter>
#include <QPushButton>
#include <QWidget>

#include "qfloodit.h"

class Cell : public QPushButton {
    Q_OBJECT
public:
    explicit Cell(unsigned color, QFloodIt& qFloodIt, QWidget* parent = nullptr);
    void changeColor(unsigned color);

private:
    QFloodIt* model;

    unsigned color;

    void arrangement();

    void behavior();

    QColor getColor();
};

#endif // CELL_H
