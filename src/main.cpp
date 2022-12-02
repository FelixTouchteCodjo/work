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
#include "amoeba.h"

void affiche(Image I);

int main(){

	Image Iref, I;
	Iref.imread("baptiste.pgm");
	I.imread("baptiste_defor.pgm");
	Evaluation m(Iref,I);
	//0.01 est la taille du simplex minimale avant arrêt de l'algo
	Amoeba opt(0.01);

	/*Point de départ*/
	VecDoub ystart(3);
	//Initialisation
	ystart[0]=5;
	ystart[1]=0;
	ystart[2]=0;
	/*resultat*/
	VecDoub yfinal1(3);

	yfinal1 = opt.minimize(ystart,2.,m); //2 est la taille du simplex au départ
	std::cout << "ystart " << ystart[0] << " " << ystart[1] << " " << ystart[2] << m(ystart) << std::endl;
	std::cout << "yfinal1 " << yfinal1[0] << " " << yfinal1[1] << " " << yfinal1[2] << m(yfinal1) << std::endl;

	Transformation objTf(yfinal1[0],yfinal1[1],yfinal1[2]);
	Interpolation2 objInter(I);
	Deformation objDef(objInter,objTf);
	int nl = I.nrows(), nc = I.ncols();
	Image Idef(nl,nc), Imask(nl,nc);
	objDef.deforme(Idef,Imask);
	Idef.imwrite("baptiste_recalage.pgm");
	Imask.imwrite("baptiste_recalage_mask.pgm");

	return 1;
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

