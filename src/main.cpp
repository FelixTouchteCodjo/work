#include <iostream>
#include "nr3.h"
#include "Image.h"
#include <fstream>
#include "Point.h"
 #include "Transformation.h"
 #include "Interpolation.h"
 #include "Deformation.h"

void affiche(Image I);

int main(){
	
	/* Felix: Test de la methode interpole
	Interpolation * objInter = new Interpolation1(I);
	double ng;
	Point pf(0,0);
	pf.afficher();
	double x, y;
	std::cout << x << " " << y<< std::endl;
	if (objInter->interpole(pf,ng)) {
		std::cout << ng << std::endl;
	}
	*/

	/* Randolf: Test de la methode imread
	Image I(331,331);        // Pour tester imread
	I.imread("reference.pgm");
	affiche(I);
	*/

	/* Randolf: Test de la Classe Deformation*/
	Image I(331,331);
	I.imread("../src/reference.pgm"); 
	Image Idef(331, 331), Imask(331,331);
	//Interpolation *objInter = new Interpolation1(I);
	Interpolation1 objInter(I);
	Transformation objTf(0, 1, 1);
	Deformation objDef(objInter, objTf);
	objDef.deforme(Idef, Imask);
	affiche(Idef);
	Idef.imwrite("test.pgm");
	/* Fin_est Defomation*/
}






void affiche(Image I){
	for (int i = 0; i< I.nrows();i++) {
		for (int j = 0;j < I.ncols() ; j++){
			std::cout << I[i][j] << " ";
		}
		std::cout << std::endl;
	} 
}



