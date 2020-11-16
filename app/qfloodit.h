#ifndef QFLOODIT_H
#define QFLOODIT_H

#include <QObject>

#include "floodit.h"

/**
 * @brief The QFloodIt class is a representation of the teasing game adapted
 * to the signal/slots the qt features. This class implements only a few more
 * things than the model and simply inherits most of these methods and attributes.
 * This allows to take advantage of the observer/observable pattern offered
 * directly by the qt mechanisms.
 */
class QFloodIt : public QObject, public FloodIt {
    Q_OBJECT
public:
    /**
     * @brief QFloodIt allows to create a Taquin modele with qt features.
     *
     * @param parent the parent of the QTaquin instance.
     * The new class is deleted when its parent is deleted..
     */
    explicit QFloodIt(QObject* parent = nullptr);

    /**
     * @brief pickColor allows to pick a color on the board game.
     *
     * @param color the color to be picked.
     */
    void pickColor(unsigned color);

signals:
    /**
     * @brief boardChanged is a signal indicating that the board has changed.
     */
    void boardChanged();

    /**
     * @brief gameFinished is a signal indicating that the game is finished.
     */
    void gameFinished();
};

#endif // QFLOODIT_H
