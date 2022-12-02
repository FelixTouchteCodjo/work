#include "Similarite.h"
#include "nr3.h"

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
Similarite2::Similarite2(const Image & I1_, const Image & I2_, const Image & Imask1_, const Image & Imask2_)
    : Similarite(I1_,I2_,Imask1_,Imask2_) {}

double Similarite2::ressemblance(){  // les matrices ont mêmes dimensions
    int nl = I1.nrows();
    int nc = I2.ncols();
    Image I1q(nl,nc);
    Image I2q(nl,nc);
    for (int i=0;i<nl;i++){
        for (int j=0;j<nc;j++){
            I1q[i][j] = floor((I1[i][j])/16)*(Imask1[i][j])*(Imask1[i][j]); // vaut 0 si x,y not in support commun
            I2q[i][j] = floor((I2[i][j])/16)*(Imask2[i][j])*(Imask2[i][j]);
        }
    }

    VecDoub proba1(16);
    VecDoub proba2(16);
    int N = nl*nc;
    for (int k=0;k<16;k++){
        
    }

    return 0;
}