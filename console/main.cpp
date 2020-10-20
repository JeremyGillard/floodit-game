#include "controller.h"
#include "floodit.h"
#include "view.h"

int main()
{
    FloodIt model;
    View view(model);
    Controller controller(model, view);

    controller.startGame();

    return 0;
}
