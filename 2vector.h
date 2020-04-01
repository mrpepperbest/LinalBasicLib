
#ifndef LINALLIB_2VECTOR_H
#define LINALLIB_2VECTOR_H
#include <iostream>
#include <iomanip>
#include "Nvector.h"
using namespace std;
//2 dimensional vector(basics)
class Vector2D:public Vector {
private:
protected:

public:
    Vector2D() :Vector(2) {}; //empty init
    Vector2D(double x, double y) { //init with known x and y
        this->dim = 2;
        coords = new double[dim];
        coords[0]=x;
        coords[1]=y;
    };

    ~Vector2D() { //destruction
        delete[] coords;
    }
    //funcs for finding out dimensions and coordinates
    double getX() const {
        return this->getNcord(0);
    };
    double getY() const {
        return this->getNcord(1);
    };
    void setX(double x){
        this->setNcord(0,x);
    };
void setY(double y){
    this->setNcord(1,y);
};
//operators
bool operator==(const Vector2D& v) const { //equality
    return ((this->getX()==v.getX())&&(this->getY()==v.getY()));
};
bool operator != (const Vector2D& v) const //inequality
{
    return !(*this == v);
}

};
#endif //LINALLIB_2VECTOR_H
