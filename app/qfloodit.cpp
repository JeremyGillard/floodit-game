#include "qfloodit.h"

QFloodIt::QFloodIt(QObject* parent)
    : QObject(parent)
    , FloodIt()
{
}

void QFloodIt::pickColor(unsigned color)
{
    FloodIt::pickColor(color);
    if (FloodIt::isOver())
        emit gameFinished();
    emit boardChanged();
}
