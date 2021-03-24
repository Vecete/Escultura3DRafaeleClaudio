#include "cutvoxel.h"

CutVoxel::CutVoxel(int x,int y,int z)
{
    nx = x;
    ny = y;
    nz = z;
}

void CutVoxel::draw(Sculptor &t)
{
    t.cutVoxel(nx,ny,nz);
}
