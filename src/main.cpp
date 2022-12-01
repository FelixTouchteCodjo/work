#include <iostream>
#include "nr3.h"
#include "Image.h"
#include <fstream>
#include "Point.h"
#include "Transformation.h"
#include "Interpolation.h"
#include "Deformation.h"
#include "Similarite.h"
#include "Evaluation.h"

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
	Image Iref, I;
	Iref.imread("reference.pgm");
	I.imread("floating.pgm");
	// int nn = I.nrows(), mm = I.ncols();
	// Image Idef(nn,mm), Imask(nn,mm);
	// // Interpolation *objInter = new Interpolation1(I);
	// Interpolation1 objInter(I);
	// Transformation objTf(0.785,0,0);
	// Deformation objDef(objInter, objTf);
	// objDef.deforme(Idef, Imask);
	// //affiche(Idef);
	// Idef.imwrite("Idef.pgm");
	// Imask.imwrite("Imask.pgm");
	// /* Fin_est Defomation*/
	// Image Iones(nn,mm,255);
	// Similarite1 objSim(I,Idef,Iones,Imask);
	// cout << "Similarité = " << objSim.ressemblance() << endl;
	Evaluation E(Iref,I);
	VecDoub v(3);
	v[0] = 0.785; v[1] = 0; v[2] = 0;
	cout << "Similarité = " << E(v) << endl;

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
