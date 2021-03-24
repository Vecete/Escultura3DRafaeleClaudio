#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "figurageometrica.h"

class PutEllipsoid:
        public FiguraGeometrica
{
    int nx0,ny0,nz0,nraiox,nraioy,nraioz;
    float nr,ng,nb,na;

public:
    PutEllipsoid(int x0, int y0, int z0, int raiox, int raioy, int raioz, float r, float g, float b, float a);
    void draw(Sculptor &t);
};

#endif // PUTELLIPSOID_H
