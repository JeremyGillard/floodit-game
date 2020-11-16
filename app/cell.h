#ifndef CELL_H
#define CELL_H

#include <QPainter>
#include <QPushButton>
#include <QWidget>

#include "qfloodit.h"

/**
 * @brief The Cell class represent a cell of the board of the game FloodIt.
 */
class Cell : public QPushButton {
    Q_OBJECT
public:
    /**
     * @brief Cell allows to create a cell with a given color on game board.
     *
     * @param color the color to represent in the cell.
     * @param qFloodIt the model whose cell represents a fragment of the game board.
     * @param parent parent who will be in charge of its destruction.
     */
    explicit Cell(unsigned color, QFloodIt& qFloodIt, QWidget* parent = nullptr);

    /**
     * @brief changeColor allows to change the real color of the cell based on
     * the color (unsigned) associate with it.
     *
     * @param color the (unsigned) color representation associate with it.
     */
    void changeColor(unsigned color);

private:
    QFloodIt* model;

    unsigned color;

    void arrangement();

    void behavior();

    QColor getColor();
};

#endif // CELL_H
