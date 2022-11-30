#include <iostream>
#include "nr3.h"
#include "Image.h"
#include <fstream>


int main(){
	std::ifstream lecture("tmp.txt");
	char c[2];
	double data;
	lecture >> c;
	lecture >> data;
	std::cout << c << " " << data << std::endl;
}

void affiche(Image I){
	for (int i = 0; i< I.nrows();i++) {
		for (int j = 0;j < I.ncols() ; j++){
			std::cout << I[i][j] << " ";
		}
		std::cout << std::endl;
	} 
}



