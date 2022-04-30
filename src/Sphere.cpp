#include "Sphere.h"

Sphere::Sphere()
{
}

Sphere::~Sphere()
{
}

bool Sphere::hit(const Ray &ray, double &tmin) const
{
    Vector3 temp = ray.origin - center;
    double a = ray.direction * ray.direction;
    double b = 2 * temp * ray.direction;
    double c = (temp * temp) - (radius * radius);
    double discrim = (b * b) - (4 * a * c);
    if (discrim < 0.0)
        return false;
    else
    {
        double e = sqrt(discrim);
        double denom = 2 * a;
        double t = (-b - e) / denom; // small root
        if ((t > KEpsilon) && (t <= tmin))
        {
            tmin = t;
            return true;
        }
        t = (-b + e) / denom; // big root
        if ((t > KEpsilon) && (t <= tmin))
        {
            tmin = t;
            return true;
        }

        else
            return false;
    }
}
