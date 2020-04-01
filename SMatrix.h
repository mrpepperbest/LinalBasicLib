
#ifndef LINALLIB_SMATRIX_H
#define LINALLIB_SMATRIX_H
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Matrix.h"
using namespace std;
class SMatrix:public Matrix {
private:
protected:
unsigned int size;
public:
    SMatrix() :Matrix(1,1) {}; //empty init
    SMatrix(unsigned int n) { //init with known size
        this->strokes= n;
        this->columns= n;
        this->size=n;
        matrix = new double[n*n]{0};
    };

    ~SMatrix() { //destruction
        delete[] matrix;
    }
    unsigned int getSize(){
        return this->size;
    }
    void setSize(unsigned int a){
        this->size=a;
    }
    //determinant
    double det(){
        if(this->size==1){
            return (this->matrix[0]);
        }
        if(this->size==2) {
            return ((this->matrix[0] * this->matrix[3]) - (this->matrix[1] * this->matrix[2]));
        }
        double q=0;
        for(unsigned int i=0;i<this->getH();++i){
            SMatrix A(this->getH()-1);
            unsigned int p=0;
            for(unsigned int j=1;j<(this->size);++j){
                for(unsigned int p=0;p<(this->size);++p){
                    if(p<i){
                        A.setMNe(j-1,p,this->getMNe(j,p));
                    }
                    if(p>i){
                        A.setMNe(j-1,p-1,this->getMNe(j,p));
                    }
            }
        }
            q+=(A.det()*this->getIe(i));
        }
        return q;
    }
};
istream& operator>> (istream& is, SMatrix& m) //inputting matrix
{
    unsigned int N;
    double c;
    is >>N;
    m.setW(0);
    m.setH(N);
    m.setW(N);
    m.setSize(N);
    for (unsigned int i = 0; i < N; ++i) {
        for (unsigned int j = 0; j < N; ++j) {
            is >> c;
            m.setMNe(i,j, c);
        }
    }
    return is;
}
#endif //LINALLIB_SMATRIX_H
