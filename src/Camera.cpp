#include "Camera.h"

Camera::Camera(void) : eye(0.0, 0.0, 0.0), lookAt(0.0, 0.0, -10.0), up(0.0, 1.0, 0.0)
{
    w = (-(lookAt - eye)).hat();
    u = (up ^ w).hat();
    v =  (w ^ u).hat();
    vp = new ViewPlane();
}

Camera::~Camera()
{
    // delete vp;
}
