#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include "GeometricObject.h"
#include "Camera.h"
#include "Light.h"


class World
{
public:
    std::vector<GeometricObject*> objects;
    Camera camera;
    Light light;
    RGBColor backGroundColor;
    
    
    
    World(void);
    ~World();


};




#endif