#include "RGBColor.h"

RGBColor::RGBColor(void) : r(0.0f), g(0.0f), b(0.0f), a{0.0f} {}

RGBColor::RGBColor(float rChannel, float gChannel, float bChannel) : r(rChannel), g(gChannel), b(bChannel), a(0.0f) {}
RGBColor::RGBColor(const RGBColor &color) : r(color.r), g(color.g), b(color.b), a(color.a) {}
RGBColor &RGBColor::operator=(const RGBColor &rhs)
{
    if (this != &rhs)
    {
        r = rhs.r;
        g = rhs.g;
        b = rhs.b;
        a = rhs.a;
    }
    return *this;
}

RGBColor::~RGBColor() {}
