#include "Deformation.h"

Deformation::Deformation(Interpolation &objInter, const Transformation & objTf): Tf(objTf)
{
    pInter = &objInter;
}

void Deformation::deforme(Image & Idef, Image & Imask)
{
    for (int i(0); i<Idef.nrows(); i++)
    {
        for (int j(0); j<Idef.ncols();j++)
        {   Point pi(i, j), pf;
            double ng; // niveau de gris 
            bool in_out; // valeur des pixels de Imask
            Tf.transforme(pi,pf); // on trouve l'image du pixel (i, j) de I
            cout << "Pi : " ; pi.afficher();
            cout << "Pf : " ; pf.afficher();
            in_out = pInter->interpole(pf, ng); // on determine Idef(s) = I(s')
            // cout << "INTERPOLATION EFFECTUE AVEC SUCCES" << endl;
            // cout << "in_out: " << in_out <<endl;
            // cout << "ng: " << ng <<endl;
            cout << "j: " << j <<endl; 
            cout << "i: " << i <<endl; 


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