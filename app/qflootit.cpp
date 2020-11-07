#include "qflootit.h"

QFlootIt::QFlootIt(QObject* parent)
    : QObject(parent)
    , FloodIt()
{
}

void QFlootIt::pickColor(unsigned color)
{
    FloodIt::pickColor(color);
    if (FloodIt::isOver())
        emit gameFinished();
    emit boardChanged();
}
