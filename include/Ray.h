#ifndef __RAY__
#define __RAY__

#include "Point3.h"
#include "Vector3.h"

class Ray
{
public:
    Point3 origin;
    Vector3 direction;

    Ray(void);
    Ray(const Point3 &o, const Vector3 &d);
    Ray(const Ray &r);
    Ray &operator=(const Ray &rhs);
    ~Ray(void);
};

#endif