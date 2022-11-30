#ifndef INTERPOLATION_H
#define INTERPOLATION_H
#include <math.h>
#include "Point.h"
#include "Image.h"

class Interpolation { 
    protected :
        Image I;
    public :
        Interpolation(const Image & I);
        virtual bool interpole(const Point & pf, double & ng) = 0;
};

class Interpolation1 : public 

#endif