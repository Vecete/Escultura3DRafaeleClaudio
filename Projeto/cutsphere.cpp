#include "cutsphere.h"

#include <cmath>

CutSphere::CutSphere(int x0, int y0, int z0, int raio)
{
    nx0 = x0;
    ny0 = y0;
    nz0 = z0;
    nraio = raio;
}

void CutSphere::draw(Sculptor &t)
{
    int i,j,k;
    float distx,disty,distz;
    for(i = nx0 - nraio;i < (nx0+nraio);i++){
        distx = (float)(i-nx0)/(float)nraio;
        for(j = ny0 - nraio; j < (ny0+nraio);j++){
            disty = (float)(j-ny0)/(float)nraio;
            for(k = nz0 - nraio; k < (nz0+nraio);k++){
                distz = (float)(k-nz0)/(float)nraio;
                if(pow(distx,2)+pow(disty,2)+pow(distz,2) <= 1.00){
                    t.putVoxel(i,j,k);
                }
            }
        }
    }
}
