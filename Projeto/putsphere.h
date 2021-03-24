#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "figurageometrica.h"
class PutSphere:
        public FiguraGeometrica
{
    int nx0,ny0,nz0,nraio;
    float nr,ng,nb,na;
public:
    PutSphere(int x0, int y0, int z0, int raio, float r, float g, float b, float a);
    void draw (Sculptor &t);
};

#endif // PUTSPHERE_H
