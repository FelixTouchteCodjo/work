#include "Similarite.h"


Similarite::Similarite(const Image & I1_, const Image & I2_, const Image & Imask1_, const Image & Imask2_){
    I1 = I1_; I2 = I2_; Imask1 = Imask1_; Imask2 = Imask2_;
}

Similarite1::Similarite1(const Image & I1_, const Image & I2_, const Image & Imask1_, const Image & Imask2_)
    : Similarite(I1_,I2_,Imask1_,Imask2_) {}

double Similarite1::ressemblance(){  // les matrices ont mêmes dimensions
    int nl = I1.nrows();
    int nc = I2.ncols();
    int N = nl*nc; 
    double S = 0;
    double Smask = 0;
    for (int i(0);i<nl;i++){
        for (int j(0);j<nc;j++){
            S += (I2[i][j] - I1[i][j])*(I2[i][j] - I1[i][j])*Imask1[i][j]*Imask2[i][j];
            Smask += Imask1[i][j]*Imask2[i][j];
        }
    }
    S = S/(Smask);
    return S;
}
