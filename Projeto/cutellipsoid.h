#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "figurageometrica.h"

class CutEllipsoid:
        public FiguraGeometrica
{
    int nx0,ny0,nz0,nraiox,nraioy,nraioz;
public:
    CutEllipsoid(int x0, int y0, int z0, int raiox, int raioy, int raioz);
    void draw(Sculptor &t);
};

#endif // CUTELLIPSOID_H
