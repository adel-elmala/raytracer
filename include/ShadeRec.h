#ifndef SHADEREC_H
#define SHADEREC_H
#include "Point3.h"
#include "RGBColor.h"
#include "Normal3.h"

struct ShadeRec
{
    /* data */
    Point3 hitPoint;
    RGBColor diffuseColor;
    RGBColor specularColor;
    Normal3 n;
    float  phongExponent;
    double tmin;

};


#endif