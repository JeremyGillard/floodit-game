#include "cell.h"

#include <QDebug>

int BOARD_SIZE = 400;

Cell::Cell(const QString& text, unsigned i, unsigned j, QFloodIt& qFloodIt, QWidget* parent)
    : QPushButton(text, parent)
    , model(&qFloodIt)
    , i(i)
    , j(j)
{
    arrangement();
    behavior();
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
            model->pickColor(model->getColorAt(i, j));
        }
    });
}
