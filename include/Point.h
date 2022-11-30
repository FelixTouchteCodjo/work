#ifndef POINT_H
#define POINT_H
#include <math.h>
#include <iostream>

class Point{
    private :
        double abs, ord;
    public :
        Point(double x = 0, double y = 0){
            abs = x; ord = y;
        }
        void obtenirCoord(double &x, double &y){
            x = abs; y = ord;
        }
        void translater(double x, double y){
            abs += x; ord += y;
        }
        void rotationner(double theta){
            double x = abs, y = ord;
            abs = cos(theta)*x - sin(theta)*y;
            ord = sin(theta)*x + cos(theta)*y;
        }
        void afficher(){
            std::cout << "Point : " << abs << "," << ord << std::endl;
        }
};


#endif