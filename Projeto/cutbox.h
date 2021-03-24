#ifndef CUTBOX_H
#define CUTBOX_H

#include "figurageometrica.h"

class CutBox:
    public FiguraGeometrica
{
    int nx0,ny0,nz0,nx1,ny1,nz1;
public:
    CutBox(int x0, int y0, int z0, int x1, int y1, int z1);
    void draw(Sculptor &t);
};

#endif // CUTBOX_H
