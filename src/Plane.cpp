#include "Plane.h"

Plane::Plane()
{
    p = Point3(0.0,-10.0,0.0);
    n = Normal3(0.0, 1.0, 0.0);
    color = RGBColor(0.6f, 0.3f, 0.4f);
    specularColor = RGBColor(0.5, 0.5, 0.5);
    PhongExponent = 100;
}

Plane::~Plane()
{
}

bool Plane::hit(const Ray &ray, double &tmin, ShadeRec &Rec) const
{
    double nominator = (p - ray.origin) * n;
    double denom = (ray.direction) * n;
    double t = nominator / denom;
    bool hit = false;

    if ((t > KEpsilon) && (t <= tmin))
    {
        tmin = t;
        Rec.hitPoint = ray.origin + (t * ray.direction);
        Rec.diffuseColor = color;
        Rec.specularColor = specularColor;
        Rec.n = n;
        Rec.phongExponent = PhongExponent;
        Rec.tmin = t;
        hit = true;
    }

    return hit;
}
