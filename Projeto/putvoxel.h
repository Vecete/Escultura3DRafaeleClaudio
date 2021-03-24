#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "figurageometrica.h"

class PutVoxel:
public FiguraGeometrica{
    int nx,ny,nz;
    float nr,ng,nb,na;


public:
    PutVoxel(int x,int y,int z,float r,float g,float b,float a);
    void draw(Sculptor &t);
    ~PutVoxel();

};

#endif // PUTVOXEL_H
