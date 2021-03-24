#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "figurageometrica.h"


class CutSphere:
        public FiguraGeometrica
{
    int nx0,ny0,nz0,nraio;
public:
    CutSphere(int x0, int y0, int z0, int raio);
    void draw(Sculptor &t);
};

#endif // CUTSPHERE_H
