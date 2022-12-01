#include "Evaluation.h"

Evaluation::Evaluation (Image Iref_, Image I_) {Iref = Iref_; I = I_;}

double Evaluation::operator() (VecDoub & v){  // vecteur de paramètres theta, tx et ty
    double theta = v[0], tx = v[1], ty = v[2];
    // définition d'une transformation
    Transformation objTf(theta,tx,ty);
    Interpolation1 objInter(I);
    Deformation objDef(objInter,objTf); // fin définition transformation
    int nl = I.nrows(), nc = I.ncols();
    Image Idef(nl,nc), Imask(nl,nc);
    objDef.deforme(Idef,Imask);
    Image ImaskRef(nl,nc,255); 
    Similarite1 S(Iref,Idef,ImaskRef,Imask);
    return S.ressemblance();
}
