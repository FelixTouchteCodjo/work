#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H
#include <math.h>
#include "Point.h"

class Transformation{ 
    private :
        double theta, tx, ty;
    public :
        Transformation(double vtheta, double vtx, double vty);
        void transforme(const Point & pi, Point & pf);
};


#endif