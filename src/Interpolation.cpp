#include "Interpolation.h"

Interpolation::Interpolation(const Image & I_ ){
    I = I_;
}

Interpolation1::Interpolation1(const Image & I_) : Interpolation(I_){;} // constructeur de Interpolation1

// Algorithme fourni par le prof
bool Interpolation1::interpole(const Point & pf, double & ng){ // bool = in/out selon que pf appartienne ou non au support
    double x, y;
    pf.obtenirCoord(x,y);
    int H = I.nrows();
    int L = I.ncols();
    if ( (x < 0) || (x > H) || (y < 0) || (y > L-1) ) {
        std::cout << "Je suis rentré. False" << std::endl;
        return false;
    }
    else if ((x == 0) || (x == H) || (y == 0) || (y == L-1) ) { // petit modif par rapport à l'algo du prof pour éviter les segemntations false
        int i = (int) x;
        int j = (int) y;
        ng = I[i][j];
        return true;
    }
    else {
        int i1, i2,j1,j2;
        double dx, dy, dfx, dfy, dfxy, res;

        i1 = floor(x);
        j1 = floor(y);
        if ( i1 == H-1)
            i1 --;
        if (j1 == L-1)
            j1--;
        i2 = i1 + 1;
        j2 = j2 + 1;
        
        // Le point (x,y) est dans le carré défini par le spoints discrets (i1,j1),(i1,j2),(i2,j1),(i2,j2).
        dx = x - i1;
        dy = y - j1;
        std::cout << "Je suis arrivé jusque là. True" << std::endl;
        dfx = I[i2][j1] - I[i1][j1]; std::cout << "tmp" << dfy<< std::endl;
        dfy = I[i1][j2] - I[i1][j1]; 
        dfxy = I[i1][j1] + I[i2][j2] - I[i2][j1] - I[i1][j2];
        
        res = I[i1][j1] + dfx*dx + dfy*dy + dx*dy*dfxy;
        ng = res; // la valeur de I au point (x,y) est res
        return true; 
    }
}
