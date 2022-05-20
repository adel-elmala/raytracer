#include "Light.h"
Light::Light()
{
    pos = Point3(100.0, 0.0, 0.0);
    dir = pos - Point3(0);
    RedIntensity = 0.5f;   
    GreenIntensity = 0.5f;   
    BlueIntensity = 0.5f;   
}

Light::~Light()
{
}
