#include <iostream>
#include "nr3.h"
#include "Image.h"
#include <fstream>
#include "Point.h"
 #include "Transformation.h"
 #include "Interpolation.h"


int main(){
	
	Point A(2,3);
    Point B;
	A.afficher();
	B.afficher();
    Transformation Tf(3.14,0,0);
    Tf.transforme(A,B);
	A.afficher();
	B.afficher();
}

void affiche(Image I){
	for (int i = 0; i< I.nrows();i++) {
		for (int j = 0;j < I.ncols() ; j++){
			std::cout << I[i][j] << " ";
		}
		std::cout << std::endl;
	} 
}



