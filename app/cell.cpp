#include "cell.h"

int BOARD_SIZE = 400;
//const int FONT_SIZE = 24;
//const QString FONT_FAMILLY = "Tahoma";

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
    setMinimumSize(BOARD_SIZE / model->chosenWidth(), BOARD_SIZE / model->chosenHeight());
}

void Cell::behavior()
{
    connect(this, &Cell::clicked, this, [&]() {
        if (!model->isOver()) {
            model->pickColor(model->getColorAt(i, j));
        }
    });
}
