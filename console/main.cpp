#include "controller.h"
#include "floodit.h"
#include "view.h"

/*!
 * \mainpage Flood It - Console
 *
 * This is the documentation concerning the game console part.
 */

int main()
{
    FloodIt model;
    View view(model);
    Controller controller(model, view);

    controller.startGame();

    return 0;
}
