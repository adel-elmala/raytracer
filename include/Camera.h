#ifndef CAMERA_H
#define CAMERA_H

#include "Point3.h"
#include "ViewPlane.h"
// class ViewPlane;
class Camera
{
    
public:
    Point3 eye;
    Point3 lookAt;
    Vector3 up;
    Vector3 u,v,w;
    ViewPlane *vp;


    Camera(void);
    ~Camera();
    void setup_uvw();
    
    // virtual Vector3 rayDirection() = 0; // start with orthographic camera first
};


#endif