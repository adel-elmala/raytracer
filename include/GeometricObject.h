#ifndef _GEOMETRICOBJECT_
#define _GEOMETRICOBJECT_

#include "float.h"
#include "Ray.h"
#include "RGBColor.h"
#include "ShadeRec.h"

const double KEpsilon = DBL_MIN;

class GeometricObject
{

public:
    // GeometricObject(const RGBColor& col);
    // GeometricObject(const GeometricObject& object);
    // GeometricObject& operator=(const GeometricObject& rhs);
    GeometricObject(void);
    ~GeometricObject();
    
    // used for shading
    RGBColor color;
    RGBColor specularColor;
    float PhongExponent;

    virtual bool hit(const Ray &ray, double &tmin, ShadeRec &Rec) const = 0;
};

#endif