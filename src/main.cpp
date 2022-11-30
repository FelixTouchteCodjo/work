#include <iostream>
#include "nr3.h"
#include "Image.h"
#include <fstream>
#include "Point.h"
 #include "Transformation.h"
 #include "Interpolation.h"

void affiche(Image I);

int main(){
	Image I(2,3);
	affiche(I);
	Interpolation * objInter = new Interpolation1(I);
	double ng;
	Point pf(0,0);
	pf.afficher();
	double x, y;
	std::cout << x << " " << y<< std::endl;
	if (objInter->interpole(pf,ng)) {
		std::cout << ng << std::endl;
	}
	// Image I(331,331);        // Pour tester imread
	// I.imread("reference.pgm");
	// affiche(I);
}

void affiche(Image I){
	for (int i = 0; i< I.nrows();i++) {
		for (int j = 0;j < I.ncols() ; j++){
			std::cout << I[i][j] << " ";
		}
		std::cout << std::endl;
	} 
}



