#include <cstdio>
#include "Matrix3.h"

int main(int argc, const char *argv[])
{
    Matrix3 m;
    m(0,0) = 1.0;
    m(0,1) = 1.0;
    m(0,2) = 2.0;
    
    m(1,0) = 2.0;
    m(1,1) = 1.0;
    m(1,2) = 3.0;
    
    m(2,0) = 1.0;
    m(2,1) = 4.0;
    m(2,2) = 2.0;
    m.prettyPrint();
    
    Vector3 v(3.0,1.0,2.0);
    Vector3 tmp = m*v;
    tmp.prettyPrint();
    
    Matrix3 tmp2 = m*m;
    tmp2.prettyPrint();

    Matrix3 tmp3 = tmp2.transpose();
    tmp3.prettyPrint();

    Matrix3 tmp4 = tmp3 * 2.0;
    Matrix3 tmp5 = 2.0 * tmp3 ;
    tmp4.prettyPrint();
    tmp5.prettyPrint();


    return 0;
}