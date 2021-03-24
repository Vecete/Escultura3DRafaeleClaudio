#include "cutbox.h"

CutBox::CutBox(int x0, int y0, int z0, int x1, int y1, int z1)
{
    nx0 = x0;
    ny0 = y0;
    nz0 = z0;
    nx1 = x1;
    ny1 = y1;
    nz1 = z1;
}

void CutBox::draw(Sculptor &t){
    int i,j,k;
    for(i = nx0;i<nx1;i++){
        for(j = ny0; j < ny1;j++){
            for(k = nz0; k < nz1;k++){
                t.cutVoxel(i,j,k);
            }
        }
    }
}
