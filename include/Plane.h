#ifndef PLANE_H
#define PLANE_H

#include "Point3.h"
#include "Normal3.h"
#include "GeometricObject.h"
class Plane : public GeometricObject
{
public:
    Point3 p;
    Normal3 n;

    virtual bool hit(const Ray &ray, double &tmin, ShadeRec &Rec) const;

    Plane();
    ~Plane();
};

#endif