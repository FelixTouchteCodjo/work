#include <iostream>
#include "nr3.h"
#include "Image.h"
#include <fstream>
#include "Point.h"
#include "Transformation.h"
#include "Interpolation.h"
#include "Deformation.h"

void affiche(Image I);

int main()
{

	// Felix: Test de la methode interpole
	// Image I (2,3,120);
	// Interpolation * objInter = new Interpolation1(I);
	// double ng;
	// Point pf(1,2);
	// pf.afficher();
	// if (objInter->interpole(pf,ng)) {
	// 	std::cout << " ng = " << ng << std::endl;
	// }
	

	// // Randolf: Test de la methode imread
	// Image I(25,25,120);        // Pour tester imread
	//I.imwrite("myfile.pgm");
	//affiche(I);
	

	// /* Randolf: Test de la Classe Deformation*/
	Image I;
	I.imread("reference.pgm");
	int nn = I.nrows(), mm = I.ncols();
	Image Idef(nn,mm), Imask(nn,mm);
	// Interpolation *objInter = new Interpolation1(I);
	Interpolation1 objInter(I);
	Transformation objTf(0.785,0,0);
	Deformation objDef(objInter, objTf);
	objDef.deforme(Idef, Imask);
	//affiche(Idef);
	Idef.imwrite("test.pgm");
	/* Fin_est Defomation*/
}

void affiche(Image I)
{
	for (int i = 0; i < I.nrows(); i++)
	{
		for (int j = 0; j < I.ncols(); j++)
		{
			std::cout << I[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
