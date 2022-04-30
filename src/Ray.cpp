#include "Ray.h"

Ray::Ray(void) {}

Ray::Ray(const Point3 &o, const Vector3 &d) : origin{o}, direction{d} {}
Ray::Ray(const Ray &r)
{
    if (this != &r)
    {
        this->origin = r.origin;
        this->direction = r.direction;
    }
}
Ray &Ray::operator=(const Ray &rhs)
{
    if (this != &rhs)
    {
        this->origin = rhs.origin;
        this->direction = rhs.direction;
    }
    return (*this);
}
Ray::~Ray(void) {}
