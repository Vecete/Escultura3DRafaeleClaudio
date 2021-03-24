#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include "arquivorecursos.h" 

using std::cout;
using std::cin;

int main()
{
	std::vector<FiguraGeometrica*> figs;
	std::ifstream arq("testezao.txt", std::ios::in);

	std::string part1;
	int nx, ny, nz;


	int x, y, z,
		x1, y1, z1,
		rd, rdx, rdy, rdz;
	float r, g, b, a;

	if (!arq) {
		std::cerr << "Falha ao abrir o arquivo.\n";
		std::exit(1);
	}

	arq >> part1 >> nx >> ny >> nz;
	Sculptor sculp(nx, ny, nz);
	cout << "Tamanho da estrutura: " << nx << "x" << ny << "x" << nz << "\n\n";

	while (arq >> part1) {

		if ("putvoxel" == part1) {

			arq >> x >> y >> z
				>> std::setprecision(2) >> r >> std::setprecision(2) >> g >> std::setprecision(2) >> b >> std::setprecision(2) >> a;

			figs.push_back(new PutVoxel(x, y, z, r, g, b, a));
		}
		else if ("cutvoxel" == part1) {
			arq >> x >> y >> z;

			figs.push_back(new CutVoxel(x, y, z));
		}
		else if ("putbox" == part1) {
			arq >> x >> x1
				>> y >> y1
				>> z >> z1
				>> std::setprecision(2) >> r >> std::setprecision(2) >> g >> std::setprecision(2) >> b >> std::setprecision(2) >> a;

			figs.push_back(new PutBox(x, y, z, x1, y1, z1, r, g, b, a));
		}
		else if ("cutbox" == part1) {
			arq >> x >> x1
				>> y >> y1
				>> z >> z1;
			figs.push_back(new CutBox(x, y, z, x1, y1, z1));

		}
		else if ("putsphere" == part1) {
			arq >> x >> y >> z
				>> rd
				>> std::setprecision(2) >> r >> std::setprecision(2) >> g >> std::setprecision(2) >> b >> std::setprecision(2) >> a;

			figs.push_back(new PutSphere(x, y, z, rd, r, g, b, a));
		}
		else if ("cutsphere" == part1) {
			arq >> x >> y >> z
				>> rd;
			figs.push_back(new CutSphere(x, y, z, rd));
		}
		else if ("putellipsoid" == part1) {
			arq >> x >> y >> z
				>> rdx >> rdy >> rdz
				>> std::setprecision(2) >> r >> std::setprecision(2) >> g >> std::setprecision(2) >> b >> std::setprecision(2) >> (a);

			figs.push_back(new PutEllipsoid(x, y, z, rdx, rdy, rdz, r, g, b, a));

		}
		else if ("cutellipsoid" == part1) {
			arq >> x >> y >> z
				>> rdx >> rdy >> rdz;

			figs.push_back(new CutEllipsoid(x, y, z, rdx, rdy, rdz));

			
		}
	}

	for (auto& fig : figs) {
		fig->draw(sculp);
		delete fig;
	}

	sculp.writeOFF("testeoff.off");
}