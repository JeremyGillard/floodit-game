#include "cell.h"

#include <QColor>
#include <QDebug>

int BOARD_SIZE = 400;

Cell::Cell(unsigned color, QFloodIt& qFloodIt, QWidget* parent)
    : QPushButton(parent)
    , model(&qFloodIt)
    , color(color)
{
    arrangement();
    behavior();
    changeColor(color);
}

QColor Cell::getColor()
{
    switch (color) {
    case 1:
        return QColor(41, 45, 122);
    case 2:
        return QColor(98, 203, 107);
    case 3:
        return QColor(170, 224, 163);
    case 4:
        return QColor(150, 133, 214);
    case 5:
        return QColor(184, 129, 61);
    case 6:
        return QColor(159, 183, 223);
    case 7:
        return QColor(222, 180, 156);
    case 8:
        return QColor(103, 34, 95);
    default:
        return QColor(30, 30, 30);
    }
}

void Cell::changeColor(unsigned color)
{
    this->color = color;
    QColor qColor = getColor();
    this->setStyleSheet(QString("background-color: %1").arg(qColor.name()));
}

void Cell::arrangement()
{
    QPushButton::setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    unsigned largestSize = model->chosenHeight() < model->chosenWidth() ? model->chosenWidth() : model->chosenHeight();
    setMinimumSize(BOARD_SIZE / largestSize, BOARD_SIZE / largestSize);
    setMaximumSize(BOARD_SIZE / largestSize, BOARD_SIZE / largestSize);
}

void Cell::behavior()
{
    connect(this, &Cell::clicked, this, [&]() {
        if (!model->isOver()) {
            model->pickColor(color);
        }
    });
}
