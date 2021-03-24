#ifndef PUTBOX_H
#define PUTBOX_H

#include "figurageometrica.h"


class PutBox:
       public FiguraGeometrica
{

    int nx0,ny0,nz0,nx1,ny1,nz1;
    float nr,ng,nb,na;

public:
    PutBox(int x0, int y0, int z0, int x1, int y1, int z1, float r, float g, float b, float a);
    void draw(Sculptor &t);
};

#endif // PUTBOX_H
