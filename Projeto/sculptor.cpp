#include "sculptor.h"
#include <fstream>
#include <cmath>
#include <iostream>
#include <string>
#include <iomanip>
Sculptor::Sculptor(int _nx = 20, int _ny = 20, int _nz = 20)
{
    nx = _nx;
    ny = _ny;
    nz = _nz;
    r = 0.5;
    g = 0.5;
    b = 0.5;
    a = 0.5;
    int i;
    v = new Voxel * *[_nx];
    v[0] = new Voxel * [_nx * _ny];
    v[0][0] = new Voxel[_nx * _ny*_nz];

    if (!(v && v[0] && v[0][0])) {
        std::cerr << "Nao pode-se alocar a matriz.\n";
        std::exit(1);
    }

    for (i = 1; i < nx; i++) {
        v[i] = v[i - 1] + ny;
    }

    for (i = 1; i < nx * ny; i++) {
        v[0][i] = v[0][i - 1] + nz;
    }
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = a;
                v[i][j][k].isOn = false;
            }
        }
    }

}
Sculptor::~Sculptor(){
    delete[] v[0][0];
    delete[] v[0];
    delete[] v;
}
void Sculptor::setColor(float r, float g, float b, float alpha)
{
    if(r<0){
        r = 0;
    }else if (r>1){
        r = 1;
    }
    if(g < 0){
        g = 0;
    }else if(g>1){
        g = 1;

    }if(b < 0){
        b = 0;
    }else if(b>1){
        b = 1;
    }
    if(alpha<0){
        alpha = 0;
    }else if(alpha>1){
        alpha = 1;
    }
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = alpha;

}
void Sculptor::putVoxel(int x, int y, int z)
{
    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}

void Sculptor::cutVoxel(int x, int y, int z)
{
    v[x][y][z].isOn = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    int i, j, k;
    for (i = x0; i < x1; i++) {
        for (j = y0; j < y1; j++) {
            for (k = z0; k < z1; k++) {
                putVoxel(i,j,k);
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    int i, j, k;
    for (i = x0; i < x1; i++) {
        for (j = y0; j < y1; j++) {
            for (k = z0; k < z1; k++) {
                cutVoxel(i,j,k);
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    int i, j, k;
    float distx, disty, distz;
    for (i = 0; i < nx; i++) {
        distx = (float)(i - xcenter)/(float)radius;
        for (j = 0; j < ny; j++) {
            disty = (float)(j - ycenter)/(float)radius;
            for (k = 0; k < nx; k++) {
                distz = (float)(k - zcenter)/(float)radius;
                if (pow(distx,2) + pow(disty,2) + pow(distz,2) <= 1.00) {
                    putVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    int i, j, k;
    float distx, disty, distz;
    for (i = 0; i < nx; i++) {
        distx = (float)(i - xcenter)/(float)radius;
        for (j = 0; j < ny; j++) {
            disty = (float)(j - ycenter)/(float)radius;
            for (k = 0; k < nx; k++) {
                distz = (float)(k - zcenter)/(float)radius;
                if (pow(distx,2) + pow(disty,2) + pow(distz,2) <= 1.00) {
                    cutVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    int i,j,k;
    double distx,disty,distz;
    for(i = xcenter - rx;i < (xcenter+rx);i++){
        distx = (double)(i-xcenter)/(double)rx;
        for(j = ycenter - ry; j < (ycenter+ry);j++){
            disty = (double)(j-ycenter)/(double)ry;
            for(k = zcenter - rz; k < (zcenter+rz);k++){
                distz = (double)(k-zcenter)/(double)rz;
                if(pow(distx,2)+pow(disty,2)+pow(distz,2) <= 1.00){
                    putVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    int i,j,k;
    double distx,disty,distz;
    for(i = xcenter - rx;i < (xcenter+rx);i++){
        distx = (double)(i-xcenter)/(double)rx;
        for(j = ycenter - ry; j < (ycenter+ry);j++){
            disty = (double)(j-ycenter)/(double)ry;
            for(k = zcenter - rz; k < (zcenter+rz);k++){
                distz = (double)(k-zcenter)/(double)rz;
                if(pow(distx,2)+pow(disty,2)+pow(distz,2) <= 1.00){
                    cutVoxel(i,j,k);
                }
            }
        }
    }
}




void Sculptor::writeOFF(std::string nomearquivo)
{
    std::ofstream a;
    a.open(nomearquivo);
    int nVoxel = 0;
    int face = 0;
    int nFaces = 0;
    if(!a.is_open()){
        std::cout << "Arquivo nao encontrado.";
        return;
    }


    a << "OFF \n";
    for(int i = 0; i < nx;i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if (v[i][j][k].isOn) {
                    nVoxel++;
                }
            }
        }
    }
    a << 8 * nVoxel << " " << 6*nVoxel << " 0\n";

    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0;k < nz;k++){
                if(v[i][j][k].isOn){
                    a << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n";
                    a << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n";
                    a << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n";
                    a << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n";
                    a << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n";
                    a << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n";
                    a << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n";
                    a << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n";
                }
            }
        }
    }
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0;k < nz;k++){
                if(v[i][j][k].isOn){
                    face = 8*nFaces;
                    a << std::fixed;
                    a << "4 " << face + 0 << " " << face + 3 << " " << face + 2 << " " << face + 1 << " " << std::setprecision(2) << v[i][j][k].r << " " << std::setprecision(2) << v[i][j][k].g << " " << std::setprecision(2) << v[i][j][k].b << " " << std::setprecision(2) << v[i][j][k].a << "\n"
                      << "4 " << face + 4 << " " << face + 5 << " " << face + 6 << " " << face + 7 << " " << std::setprecision(2) << v[i][j][k].r << " " << std::setprecision(2) << v[i][j][k].g << " " << std::setprecision(2) << v[i][j][k].b << " " << std::setprecision(2) << v[i][j][k].a << "\n"
                      << "4 " << face + 0 << " " << face + 1 << " " << face + 5 << " " << face + 4 << " " << std::setprecision(2) << v[i][j][k].r << " " << std::setprecision(2) << v[i][j][k].g << " " << std::setprecision(2) << v[i][j][k].b << " " << std::setprecision(2) << v[i][j][k].a << "\n"
                      << "4 " << face + 0 << " " << face + 4 << " " << face + 7 << " " << face + 3 << " " << std::setprecision(2) << v[i][j][k].r << " " << std::setprecision(2) << v[i][j][k].g << " " << std::setprecision(2) << v[i][j][k].b << " " << std::setprecision(2) << v[i][j][k].a << "\n"
                      << "4 " << face + 3 << " " << face + 7 << " " << face + 6 << " " << face + 2 << " " << std::setprecision(2) << v[i][j][k].r << " " << std::setprecision(2) << v[i][j][k].g << " " << std::setprecision(2) << v[i][j][k].b << " " << std::setprecision(2) << v[i][j][k].a << "\n"
                      << "4 " << face + 1 << " " << face + 2 << " " << face + 6 << " " << face + 5 << " " << std::setprecision(2) << v[i][j][k].r << " " << std::setprecision(2) << v[i][j][k].g << " " << std::setprecision(2) << v[i][j][k].b << " " << std::setprecision(2) << v[i][j][k].a << "\n";
                    nFaces++;
                }
            }
        }
    }
    a.close();
}
