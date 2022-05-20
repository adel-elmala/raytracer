#include "Camera.h"

Camera::Camera(void) : eye(0.0, 0.0, 0.0), lookAt(0.0, 0.0, -10.0), up(0.0, 1.0, 0.0)
{
    w = ((eye - lookAt)).hat();
    u = (up ^ w).hat();
    v = (w ^ u).hat();
    vp = new ViewPlane();
}

Camera::~Camera()
{
    vp->~ViewPlane();
    
    // delete vp;
}

void Camera::setup_uvw()
{
    w = ((eye - lookAt)).hat();
    u = (up ^ w).hat();
    v = (w ^ u).hat();
}