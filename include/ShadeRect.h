#ifndef _SHADERECT_
#define _SHADERECT_
#include "Point3.h"
#include "Normal3.h"
#include "RGBColor.h"

class World;

class ShadeRect
{
public:
    /* data */
    bool hit_an_object;
    Point3 local_hit_point;
    Normal3 normal;
    RGBColor color;
    World &w;

    ShadeRect(void);
    ShadeRect(World &wr);
    ShadeRect(const ShadeRect &sr);
    ~ShadeRect(void);

    ShadeRect &operator=(const ShadeRect &rhs);
};

ShadeRect::ShadeRect(void) : hit_an_object(false), local_hit_point(), normal(), color() {}
ShadeRect::ShadeRect(World &wr) : hit_an_object(false), local_hit_point(), normal(), color(), w(wr) {}
ShadeRect::ShadeRect(const ShadeRect &sr) : hit_an_object(sr.hit_an_object), local_hit_point(sr.local_hit_point), normal(sr.normal), color(sr.color), w(sr.w) {}

ShadeRect &ShadeRect::operator=(const ShadeRect &rhs)
{
    if (this != &rhs)
    {
        hit_an_object = rhs.hit_an_object;
        local_hit_point = rhs.local_hit_point;
        normal = rhs.normal;
        color = rhs.color;
        // w = rhs.w;
    }   
}

ShadeRect::~ShadeRect() {}

#endif