#include <iostream>
#include "nr3.h"
#include "Image.h"
void affiche(Image I);


int main(){
	std::cout << "Salut Felix !" << std::endl;
	Image M(2,3);
	Image N(3,2,4);
	affiche(M);
	affiche(N);
}

void affiche(Image I){
	for (int i = 0; i< I.nrows();i++) {
		for (int j = 0;j < I.ncols() ; j++){
			std::cout << I[i][j] << " ";
		}
		std::cout << std::endl;
	} 
}
int foo(){}


