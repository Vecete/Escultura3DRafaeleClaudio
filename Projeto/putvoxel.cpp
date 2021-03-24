#include "putvoxel.h"

PutVoxel::PutVoxel(int x,int y,int z,float r,float g,float b,float a)
{
    nx = x;
    ny = y;
    nz = z;
    nr = r;
    ng = g;
    nb = b;
    na = a;
}

void PutVoxel::draw(Sculptor &t)
{
    t.setColor(nr,ng,nb,na);
    t.putVoxel(nx,ny,nz);
}

PutVoxel::~PutVoxel()
{
}
