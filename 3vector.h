
#ifndef LINALLIB_3VECTOR_H
#define LINALLIB_3VECTOR_H
#include <iostream>
#include <iomanip>
#include "Nvector.h"
using namespace std;
//2 dimensional vector(basics)
class Vector3D:public Vector {
private:
protected:

public:
    Vector3D() :Vector(3) {}; //empty init
    Vector3D(double x, double y,double z) { //init with known x, y and z
        this->dim = 3;
        coords = new double[dim];
        coords[0]=x;
        coords[1]=y;
        coords[2]=z;
    };

    ~Vector3D() { //destruction
        delete[] coords;
    }
    //funcs for finding out dimensions and coordinates
    double getX() const {
        return this->getNcord(0);
    };
    double getY() const {
        return this->getNcord(1);
    };
    double getZ() const{
        return this->getNcord(2);
    }
    void setX(double x){
        this->setNcord(0,x);
    };
    void setY(double y){
        this->setNcord(1,y);
    };
    void setZ(double z){
        this->setNcord(2,z);
    };
//operators
    bool operator==(const Vector3D& v) const { //equality
        return ((this->getX()==v.getX())&&(this->getY()==v.getY())&&(this->getZ()==v.getZ()));
    };
    bool operator != (const Vector3D& v) const //inequality
    {
        return !(*this == v);
    }

};
#endif //LINALLIB_3VECTOR_H
