#include "Light.h"
Light::Light()
{
    pos = Point3(20.0, 30.0, -30.0);
    dir = pos - Point3(0);
    RedIntensity = 0.5f;   
    GreenIntensity = 0.5f;   
    BlueIntensity = 0.5f;   

    AmbientRedIntensity = 0.1f;   
    AmbientGreenIntensity = 0.1f;   
    AmbientBlueIntensity = 0.1f;   
}

Light::~Light()
{
}
