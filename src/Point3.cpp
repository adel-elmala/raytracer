#include "Point3.h"
// default copy constructor
Point3::Point3(void) : m_x(0.0), m_y(0.0), m_z(0.0)
{
}
// constructor
Point3::Point3(const double x, const double y, const double z)
{
    m_x = x;
    m_y = y;
    m_z = z;
}
// constructor
Point3::Point3(const double a)
{
    m_x = a;
    m_y = a;
    m_z = a;
}
// copy constructor
Point3::Point3(const Point3 &v)
{
    m_x = v.m_x;
    m_y = v.m_y;
    m_z = v.m_z;
}
// deconstructor
Point3::~Point3()
{
    return;
}

// assignment operator
Point3 &Point3::operator=(const Point3 &rhs)
{
    if (this == &rhs)
        return (*this);
    else
    {
        m_x = rhs.m_x;
        m_y = rhs.m_y;
        m_z = rhs.m_z;

        return (*this);
    }
}
