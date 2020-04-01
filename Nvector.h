

#ifndef NVECTOR_H
#define NVECTOR_H
#include <iostream>
#include <iomanip>
using namespace std;
//N dimensional vector(basics)
class Vector {
private:
protected:
    double* coords;
    unsigned int dim;
public:
    Vector() :Vector(0) {}; //empty init
    Vector(unsigned int dim) { //init with known dims
        this->dim = dim;
        coords = new double[dim];
    };
    Vector(const Vector &v) { //copy constructor
        this->dim = v.dim;
        this->coords = new double[v.dim];
        for (unsigned int i = 0; i < v.dim; ++i) {
            this->coords[i] = v.coords[i];
        }
    };
    ~Vector() { //destruction
        delete[] coords;
    }
    //funcs for finding out dimensions and coordinates
    unsigned int getDIM() const {
        return this->dim;
    };
    double getNcord(unsigned int N) const {
        return this->coords[N];
    };
    void setDIM(unsigned int dim) {
        this->dim = dim;
        if (this->coords != nullptr) {
            delete[] coords;
        }
        coords = new double[dim];
    };
    void setNcord(unsigned int N, double c) {
        this->coords[N] = c;
    };
    //operators
    bool operator==(const Vector& v) const { //equality
        if (v.getDIM() == this->getDIM()) {
            bool res = 1;
            for (unsigned int i = 0; i < v.getDIM(); ++i) {
                res = res && (v.getNcord(i) == this->getNcord(i));
            }
            return res;
        }
        return 0;
    };
    bool operator != (const Vector& v) const //inequality
    {
        return !(*this == v);
    }
    Vector& operator=(const Vector& v){ //assignment
        this->setDIM(v.getDIM());
        for(unsigned int i=0;i<v.getDIM();++i){
            this->setNcord(i,v.getNcord(i));
        }
        return *this;
    }
    Vector operator + (const Vector& v) const //sum
    {
        Vector res;
        res.setDIM(v.getDIM());
        for (unsigned int i = 0; i < v.getDIM(); ++i) {
            res.setNcord(i, this->getNcord(i) + v.getNcord(i));
        }
        return res;
    }

    Vector operator - (const Vector& v) const //subtraction
    {
        Vector res;
        res.setDIM(v.getDIM());
        for (unsigned int i = 0; i < v.getDIM(); ++i) {
            res.setNcord(i, this->getNcord(i) - v.getNcord(i));
        }
        return res;
    }


    double operator * (const Vector& v) //scalar multiplication of two vectors
    {
        double res=0;
        for (unsigned int i = 0; i < v.getDIM(); ++i) {
            res += this->getNcord(i) * v.getNcord(i);
        }
        return res;
    }
    Vector operator*(double a){ //multiplication by number
        Vector res;
        res.setDIM(this->getDIM());
        for (unsigned int i = 0; i < this->getDIM(); ++i) {
            res.setNcord(i, this->getNcord(i) * a);
        }
        return res;
    }

};
Vector operator * (const Vector& v, const double a) //multiplication by number
{
    Vector res;
    res.setDIM(v.getDIM());
    for (unsigned int i = 0; i < v.getDIM(); ++i) {
        res.setNcord(i, v.getNcord(i) * a);
    }
    return res;
}
Vector operator * (const double a, const Vector& v) //reversed multiplication by number
{
    return v * a;
}

ostream& operator << (ostream& os, const Vector& v) //outputting vector
{
    os << "(";
    for (unsigned int i = 0; i < v.getDIM() - 1; ++i) {
        os << setprecision(4)<<v.getNcord(i) << ";";
    }
    os <<setprecision(4)<< v.getNcord(v.getDIM()-1) << ")";
    return os;
}

istream& operator >> (istream& is, Vector& v) //inputting vector
{
    unsigned int dim;
    double c;
    is >> dim;
    for (unsigned int i = 0; i < dim; ++i) {
        is >> c;
        v.setNcord(i, c);
    }
    return is;
}


#endif
