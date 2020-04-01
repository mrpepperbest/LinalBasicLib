#include <iostream>
#include <iomanip>
#include "Nvector.h"
#include "2vector.h"
#include "3vector.h"
#include "Matrix.h"
#include "Smatrix.h"
using namespace std;
int main(void) {
cout << "-------Vector test---------" << endl;
    double k;
    Vector a(2);
    Vector b;
    Vector c(2);
    b.setDIM(2);
    b.setNcord(0, 1);
    b.setNcord(1, 1337);
    a.setNcord(0, 228);
    a.setNcord(1, 1);
    cout << "construction test" << endl;
    cout << a.getDIM() << endl;
    cout<< b.getDIM()<<endl;
    cout << a.getNcord(0) <<" "<< a.getNcord(1)<< endl;
    cout << b.getNcord(0) << " " << b.getNcord(1) << endl;
    cout << "equality test" << endl;
    cout << (a == b)<<endl;
    cout << (a != b)<<endl;
    b.setNcord(0, 228);
    a.setNcord(1, 1337);
    cout << (a == b)<<endl;
    cout << (a != b)<<endl;
    cout << "math test" << endl;
    cout << a.getNcord(0) << " " << a.getNcord(1) << endl;
    c = a + b;
    cout << c.getNcord(0) << " " << c.getNcord(1) << endl;
    c=c-a;
    cout << c.getNcord(0) << " " << c.getNcord(1) << endl;
    k=c*a;
    cout << setprecision(4)<< k <<endl;
    c=3*c;
    c=c*2;
    cout << c.getNcord(0) << " " << c.getNcord(1) << endl;
    cout << "io check" << endl;
    cout << c << endl;
    cout<<"input vector"<<endl;
    cin >> c;
    cout << c <<endl;
    Vector2D p(228,1111);
    Vector2D q(228,1111);
    cout << "Vector2D check" << endl;
    cout << p+q << endl;
    cout << "Vector3D check" << endl;
    Vector3D d(228,1111,322);
    Vector3D h(228,1111,544);
    cout << d+h << endl;

    cout << "-------Matrix test---------" << endl;
    cout<<"io check"<<endl;
    Matrix mat(2,2);
mat.setMNe(0,0,1);
    mat.setMNe(0,1,2);
    mat.setMNe(1,0,3);
    mat.setMNe(1,1,4);
    cout << mat;
    cout<<"input matrix"<<endl;
    cin >> mat;
    cout << mat;
    cout<<"math check"<<endl;
    Matrix mat1;
    Matrix mat2;
    cout<<"input matrix 1"<<endl;
    cin >> mat1;
    cout<<"input matrix 2"<<endl;
    cin >> mat2;
    cout << mat1+mat2;
    cout << mat1-mat2;
    cout << mat1*mat2;
    cout<<"square matrix check"<<endl;
    cout<<"enter matrix 3"<<endl;
    SMatrix mat3;
    cin >> mat3;
    cout <<mat3.det()<<endl;
    return 0;
}
