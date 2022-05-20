#include "Sphere.h"

Sphere::Sphere()
{
    specularColor = RGBColor(0.5, 0.5, 0.5);
    PhongExponent = 100;
}

Sphere::~Sphere()
{
}

bool Sphere::hit(const Ray &ray, double &tmin, ShadeRec &Rec) const
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
            Rec.tmin = t;
            Rec.hitPoint = ray.origin + t * ray.direction;
            Vector3 n = (Rec.hitPoint - center).hat();
            Rec.n = Normal3(n.m_x, n.m_y, n.m_z);
            Rec.diffuseColor = this->color;
            Rec.specularColor = this->specularColor;
            Rec.phongExponent = this->PhongExponent;
            return true;
        }
        t = (-b + e) / denom; // big root
        if ((t > KEpsilon) && (t <= tmin))
        {
            tmin = t;
            Rec.tmin = t;
            Rec.hitPoint = ray.origin + t * ray.direction;
            Vector3 n = (Rec.hitPoint - center).hat();
            Rec.n = Normal3(n.m_x, n.m_y, n.m_z);
            Rec.diffuseColor = this->color;
            Rec.specularColor = this->specularColor;
            Rec.phongExponent = this->PhongExponent;
            return true;
        }

        else
            return false;
    }
}
