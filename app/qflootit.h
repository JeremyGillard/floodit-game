#ifndef QFLOOTIT_H
#define QFLOOTIT_H

#include <QObject>

#include "floodit.h"

class QFlootIt : public QObject, public FloodIt {
    Q_OBJECT
public:
    explicit QFlootIt(QObject* parent = nullptr);
    void pickColor(unsigned color);

signals:
    void boardChanged();
    void gameFinished();
};

#endif // QFLOOTIT_H
