// #include <cstdio>
#include "Vector3.h"
#include "Point3.h"
#include "Point2.h"
#include "Normal3.h"

int main(int argc, const char *argv[])
{
    // fprintf(stdout,"hi!\n");
    Vector3 i(1.0, 0.0, 0.0);
    Vector3 j(0.0, 1.0, 0.0);
    Vector3 k = i ^ j;
    k.prettyPrint();

    Point3 p(10.0, 0.0, 0.0);
    Point3 translated = p + k; 
    translated.prettyPrint();
    Point2 p2(10.0, 0.0);
    Point2 scaled = p2 * 2;
    Point2 scaled2 = 2 * p2 ;
    scaled2.prettyPrint();
    scaled.prettyPrint();

    Normal3 n(2.0);
    n.prettyPrint();
    return 0;
}