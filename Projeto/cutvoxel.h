#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "figurageometrica.h"

class CutVoxel:
        public FiguraGeometrica
{
    int nx,ny,nz;
public:
    CutVoxel(int x, int y, int z);
    void draw(Sculptor &t);
};

#endif // CUTVOXEL_H
