
#ifndef LINALLIB_MATRIX_H
#define LINALLIB_MATRIX_H
#include <iostream>
#include <iomanip>
using namespace std;
//Matrix with M strokes and N columns
class Matrix {
private:
protected:
    double* matrix;
    unsigned int strokes;
    unsigned int columns;
public:
    Matrix() :Matrix(1,1) {}; //empty init
    Matrix(unsigned int m, unsigned int n) { //init with known size
        this->strokes= m;
        this->columns= n;
        matrix = new double[m*n]{0};
    };
    Matrix(const Matrix &m) { //copy constructor
        this->strokes= m.strokes;
        this->columns= m.columns;
        this->matrix = new double[m.columns*m.strokes];
        for (unsigned int i = 0; i < m.columns*m.strokes; ++i) {
            this->matrix[i] = m.matrix[i];
        }
    };
    ~Matrix() { //destruction
        delete[] matrix;
    }
    //funcs for finding out size and elements of matrix and pulling them in
    unsigned int getH() const {
        return this->strokes;
    };
    unsigned int getW() const {
        return this->columns;
    };
    double getMNe(unsigned int m,unsigned int n) const {
        return this->matrix[m*this->getW()+n];
    };
    double getIe(unsigned int i) const{
        return this->matrix[i];
    };
    void setH(unsigned int m) {
        this->strokes = m;
        if (this->matrix != nullptr) {
            delete[] matrix;
        }
        matrix = new double[this->strokes*this->columns];
    };
    void setW(unsigned int n) {
        this->columns = n;
        if (this->matrix != nullptr) {
            delete[] matrix;
        }
        matrix = new double[this->strokes*this->columns];
    };
    void setMNe(unsigned int m,unsigned int n, double c) {
        this->matrix[m*this->getW()+n] = c;
    };
    void setIe(unsigned int i, double c){
        this->matrix[i]=c;
    };
    //operators
    bool operator==(const Matrix& m) const { //equality
        if ((m.getW() == this->getW())&&(m.getH() == this->getH())) {
            bool res = 1;
            for (unsigned int i = 0; i < m.getH(); ++i) {
                for (unsigned int j = 0; j < m.getW(); ++j) {
                    res = res && (m.getMNe(i,j) == this->getMNe(i,j));
                }
            }
            return res;
        }
        return 0;
    };
    bool operator != (const Matrix& m) const //inequality
    {
        return !(*this == m);
    }
    Matrix& operator=(const Matrix& m){ //assignment
        this->setW(m.getW());
        this->setH(m.getH());
        for (unsigned int i = 0; i < m.columns*m.strokes; ++i) {
            this->matrix[i] = m.matrix[i];
        }
        return *this;
    }
    Matrix operator + (const Matrix& m) const //sum
    {
        Matrix res;
        res.setW(m.getW());
        res.setH(m.getH());
        for (unsigned int i = 0; i < m.columns*m.strokes; ++i) {
            res.matrix[i] = m.matrix[i]+this->matrix[i];
        }
        return res;
    }

    Matrix operator - (const Matrix& m) const //subtraction
    {
        Matrix res;
        res.setW(m.getW());
        res.setH(m.getH());
        for (unsigned int i = 0; i < m.columns*m.strokes; ++i) {
            res.matrix[i] = this->matrix[i]-m.matrix[i];
        }
        return res;
    }

    Matrix operator * (const Matrix& m) // multiplication of two matrix
    {
        if(this->getW()==m.getH()) {
            Matrix res(this->getH(), m.getW());
            for(unsigned int i =0;i<this->getH();++i){
                for(unsigned int j =0;j<m.getW();++j){
                    res.setMNe(i,j,0);
                    for(unsigned int s =0;s<m.getH();++s){
                        res.setMNe(i,j,res.getMNe(i,j)+this->getMNe(i,s)*m.getMNe(s,j));
                    }
                }
            }
            return res;
    }
        cout << "Not able to multiply"<<endl;
        return *this;
    }
    Matrix operator*(double a){ //multiplication by number
        Matrix res;
        res.setW(this->getW());
        res.setH(this->getH());
        for (unsigned int i = 0; i < this->columns*this->strokes; ++i) {
            res.matrix[i] = this->matrix[i]*a;
        }
        return res;
    }

};
Matrix operator * (const Matrix& m, const double a) //multiplication by number
{
    Matrix res;
    res.setW(m.getW());
    res.setH(m.getH());
    for (unsigned int i = 0; i < m.getH()*m.getW(); ++i) {
        res.setIe(i,m.getIe(i)*a);
    }
    return res;
}
Matrix operator * (const double a, const Matrix& m) //reversed multiplication by number
{
    return m * a;
}

ostream& operator << (ostream& os, const Matrix& m) //outputting matrix
{
    for (unsigned int i = 0; i < m.getH(); ++i) {
    os<<"| ";
    for(unsigned int j=0;j<m.getW()-1;++j){
        os << setprecision(4)<<m.getMNe(i,j) << " ";
        }
                os << setprecision(4)<<m.getMNe(i,m.getH()-1)<<" |"<<endl;
    }
    return os;
}

istream& operator>> (istream& is, Matrix& m) //inputting matrix
{
    unsigned int M,N;
    double c;
    is >> M >>N;
    m.setW(0);
    m.setH(M);
    m.setW(N);
    for (unsigned int i = 0; i < M; ++i) {
        for (unsigned int j = 0; j < N; ++j) {
            is >> c;
            m.setMNe(i,j, c);
        }
    }
    return is;
}


#endif //LINALLIB_MATRIX_H
