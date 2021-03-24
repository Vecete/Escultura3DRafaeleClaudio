#include "cutellipsoid.h"

#include <cmath>

CutEllipsoid::CutEllipsoid(int x0, int y0, int z0, int raiox, int raioy, int raioz)
{
    nx0 = x0;
    ny0 = y0;
    nz0 = z0;
    nraiox = raiox;
    nraioy = raioy;
    nraioz = raioz;

}

void CutEllipsoid::draw(Sculptor &t){
        int i,j,k;
        double distx,disty,distz;
        for(i = nx0 - nraiox;i < (nx0+nraiox);i++){
            distx = (double)(i-nx0)/(double)nraiox;
            for(j = ny0 - nraioy; j < (ny0+nraioy);j++){
                disty = (double)(j-ny0)/(double)nraioy;
                for(k = nz0 - nraioz; k < (nz0+nraioz);k++){
                    distz = (double)(k-nz0)/(double)nraioz;
                    if(pow(distx,2)+pow(disty,2)+pow(distz,2) <= 1.00){
                        t.cutVoxel(i,j,k);
                    }
                }
            }
        }
}
