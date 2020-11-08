#ifndef QFLOODIT_H
#define QFLOODIT_H

#include <QObject>

#include "floodit.h"

class QFloodIt : public QObject, public FloodIt {
    Q_OBJECT
public:
    explicit QFloodIt(QObject* parent = nullptr);
    void pickColor(unsigned color);

signals:
    void boardChanged();
    void gameFinished();
};

#endif // QFLOODIT_H
