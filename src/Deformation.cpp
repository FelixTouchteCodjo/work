#include "Deformation.h"

Deformation::Deformation(Interpolation &objInter, const Transformation & objTf): Tf(objTf)
{
    pInter = &objInter;
}

void Deformation::deforme(Image & Idef, Image & Imask)
{
    for (int i(0); i<Idef.nrows()-2; i++)
    {
        for (int j(0); j<Idef.ncols()-1;j++)
        {   Point pi(i, j), pf;
            double ng; // niveau de gris 
            bool in_out; // valeur des pixels de Imask
            Tf.transforme(pi,pf); // on trouve l'image du pixel (i, j) de I
            in_out = pInter->interpole(pf, ng); // on determine Idef(s) = I(s')
            cout << "INTERPOLATION EFFECTUE AVEC SUCCES" << endl;
            cout << "in_out: " << in_out <<endl;
            cout << "ng: " << ng <<endl;
            cout << "j: " << j <<endl; // Pour i = H-2 nous avons une segmentation error dans interpole
            cout << "i: " << i <<endl; // Pour j= L-1 nous nous une segmentation error dans interpole


            if(in_out)
            {
                Idef[i][j] = ng;
                Imask[i][j] = 1;
            }
            else
            {
                Imask[i][j] = 0;
            }

        }
    }
}

/* Exemple d'appel de la methode deforme*/
/*
Image Idef, Imask;
Interpolation *objInter = new Interpolation1(I);
Trasnformation objTf(3.14, 1, 3);
Deformation objDef (objInter, objTf);
objDef.deforme(Idef, Imask)
*/