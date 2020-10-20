#ifndef FLOODIT_H
#define FLOODIT_H

#include "board.h"

class FloodIt {
public:
    FloodIt();
    void initBoard(unsigned boardHeight, unsigned boardWidth);
    void start(unsigned difficultyLevel);
};

#endif // FLOODIT_H
