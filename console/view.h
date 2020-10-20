#ifndef VIEW_H
#define VIEW_H

#include "floodit.h"

class View {
public:
    View(FloodIt& model);

private:
    FloodIt& m_model;
};

#endif // VIEW_H
