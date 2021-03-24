#include "putellipsoid.h"

#include <cmath>

PutEllipsoid::PutEllipsoid(int x0, int y0, int z0, int raiox, int raioy, int raioz, float r, float g, float b, float a)
{
    nx0 = x0;
    ny0 = y0;
    nz0 = z0;
    nraiox = raiox;
    nraioy = raioy;
    nraioz = raioz;
    nr = r;
    ng = g;
    nb = b;
    na = a;
}

void PutEllipsoid::draw(Sculptor &t){
    int i,j,k;
    double distx,disty,distz;
    t.setColor(nr,ng,nb,na);
    for(i = nx0 - nraiox;i < (nx0+nraiox);i++){
        distx = (double)(i-nx0)/(double)nraiox;
        for(j = ny0 - nraioy; j < (ny0+nraioy);j++){
            disty = (double)(j-ny0)/(double)nraioy;
            for(k = nz0 - nraioz; k < (nz0+nraioz);k++){
                distz = (double)(k-nz0)/(double)nraioz;
                if(pow(distx,2)+pow(disty,2)+pow(distz,2) <= 1.00){
                    t.putVoxel(i,j,k);
                }
            }
        }
    }
}
