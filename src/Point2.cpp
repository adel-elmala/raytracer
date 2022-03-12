#include "Point2.h"
// default copy constructor
Point2::Point2(void) : m_x(0.0), m_y(0.0)
{
}
// constructor
Point2::Point2(const double x, const double y)
{
    m_x = x;
    m_y = y;
}
// constructor
Point2::Point2(const double a)
{
    m_x = a;
    m_y = a;
}
// copy constructor
Point2::Point2(const Point2 &v)
{
    m_x = v.m_x;
    m_y = v.m_y;
}
// deconstructor
Point2::~Point2()
{
    return;
}

// assignment operator
Point2 &Point2::operator=(const Point2 &rhs)
{
    if (this == &rhs)
        return (*this);
    else
    {
        m_x = rhs.m_x;
        m_y = rhs.m_y;
        return (*this);
    }
}
