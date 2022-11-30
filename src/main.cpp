#include <iostream>
#include "nr3.h"
#include "Image.h"
#include <fstream>
#include "Point.h"


int main(){
	Point A(2,3);
	A.afficher();
	A.rotationner(3.14);
	A.afficher();
	std::cout << cos(3.14) << std::endl;

}

void affiche(Image I){
	for (int i = 0; i< I.nrows();i++) {
		for (int j = 0;j < I.ncols() ; j++){
			std::cout << I[i][j] << " ";
		}
		std::cout << std::endl;
	} 
}



