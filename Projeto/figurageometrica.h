#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "sculptor.h"

class FiguraGeometrica
{
public:
    virtual void draw(Sculptor& t) = 0;
};

#endif // FIGURAGEOMETRICA_H
