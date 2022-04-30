#ifndef SPHERE_H
#define SPHERE_H
#include "GeometricObject.h"
class Sphere:public GeometricObject
{
public:
    Point3 center;
    float radius;
    // RGBColor color;

    Sphere();
    ~Sphere();
    virtual bool hit(const Ray &ray, double &tmin) const;

};



#endif