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

	std::string k;
	int nx, ny, nz;


	int x, y, z,
		x1, y1, z1,
		rd, rdx, rdy, rdz;
	float r, g, b, a;

	if (!arq) {
		std::cerr << "Falha ao abrir o arquivo.\n";
		std::exit(1);
	}

	arq >> k >> nx >> ny >> nz;
	Sculptor sculp(nx, ny, nz);
	cout << "Tamanho da estrutura: " << nx << "x" << ny << "x" << nz << "\n\n";

	while (arq >> k) {

		if (k.compare("putvoxel") == 0) {

			arq >> x >> y >> z
				>> std::setprecision(2) >> r >> std::setprecision(2) >> g >> std::setprecision(2) >> b >> std::setprecision(2) >> a;

			figs.push_back(new PutVoxel(x, y, z, r, g, b, a));
		}
		else if (k.compare("cutvoxel") == 0 ) {
			arq >> x >> y >> z;

			figs.push_back(new CutVoxel(x, y, z));
		}
		else if (k.compare("putbox") == 0 ) {
			arq >> x >> x1
				>> y >> y1
				>> z >> z1
				>> std::setprecision(2) >> r >> std::setprecision(2) >> g >> std::setprecision(2) >> b >> std::setprecision(2) >> a;

			figs.push_back(new PutBox(x, y, z, x1, y1, z1, r, g, b, a));
		}
		else if (k.compare("cutbox") == 0 ) {
			arq >> x >> x1
				>> y >> y1
				>> z >> z1;
			figs.push_back(new CutBox(x, y, z, x1, y1, z1));

		}
		else if (k.compare("putsphere") == 0 ) {
			arq >> x >> y >> z
				>> rd
				>> std::setprecision(2) >> r >> std::setprecision(2) >> g >> std::setprecision(2) >> b >> std::setprecision(2) >> a;

			figs.push_back(new PutSphere(x, y, z, rd, r, g, b, a));
		}
		else if (k.compare("cutsphere") == 0 ) {
			arq >> x >> y >> z
				>> rd;
			figs.push_back(new CutSphere(x, y, z, rd));
		}
		else if (k.compare("putellipsoid") == 0) {
			arq >> x >> y >> z
				>> rdx >> rdy >> rdz
				>> std::setprecision(2) >> r >> std::setprecision(2) >> g >> std::setprecision(2) >> b >> std::setprecision(2) >> (a);

			figs.push_back(new PutEllipsoid(x, y, z, rdx, rdy, rdz, r, g, b, a));

		}
		else if (k.compare("cutellipsoid") == 0) {
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
