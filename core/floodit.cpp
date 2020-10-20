#include "floodit.h"

#include <iostream>

FloodIt::FloodIt()
{
    std::cout << "Pending model construction..." << std::endl;
    Board board;
}

void FloodIt::initBoard(unsigned boardHeight, unsigned boardWidth)
{
    std::cout << "Board selected height : " << boardHeight << std::endl;
    std::cout << "Board selected width : " << boardWidth << std::endl;
}

void FloodIt::start(unsigned difficultyLevel)
{
    std::cout << "Selected difficulty : " << difficultyLevel << std::endl;
}
