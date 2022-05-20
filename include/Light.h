#ifndef LIGHT_H
#define LIGHT_H

#include "Point3.h"
#include "Vector3.h"

class Light
{
public:
    Point3 pos;
    Vector3 dir; // to be used later 
    float RedIntensity; // [0,1] range
    float GreenIntensity; // [0,1] range
    float BlueIntensity; // [0,1] range

    Light();
    ~Light();
    
};

#endif