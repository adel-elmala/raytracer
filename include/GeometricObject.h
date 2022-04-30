#ifndef _GEOMETRICOBJECT_
#define _GEOMETRICOBJECT_
#include "float.h"
#include "Ray.h"
// #include "ShadeRect.h"
#include "RGBColor.h"
const double KEpsilon = DBL_MIN;
class GeometricObject
{

public:
    // GeometricObject(const RGBColor& col);
    // GeometricObject(const GeometricObject& object);
    // GeometricObject& operator=(const GeometricObject& rhs);
    GeometricObject(void);
    ~GeometricObject();

    RGBColor color;

    virtual bool hit(const Ray &ray, double &tmin) const = 0;
};



#endif