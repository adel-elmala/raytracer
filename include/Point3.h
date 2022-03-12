#ifndef Point3_H
#define Point3_H

#include <cstdio>
#include <cmath>

#include "Vector3.h"

class Point3
{

public:
    double m_x;
    double m_y;
    double m_z;

    // default constructor
    Point3(void);
    // constructor
    Point3(const double a);
    // constructor
    Point3(const double x, const double y, const double z);
    // copy constructor
    Point3(const Point3 &v);
    // deconstructor
    ~Point3();
    Point3 operator+(const Vector3 &v) const;  // p + v
    Point3 operator-(const Vector3 &v) const;  // p - v
    Point3 operator-(void) const;              // -p
    Vector3 operator-(const Point3 &p2) const; // p1 - p2
    Point3 operator*(const double a) const;    // p * a
    Point3 &operator=(const Point3 &rhs);      // assignment operator
    double distance(const Point3 &p2) const;
    double squared_distance(const Point3 &p2) const;

    void prettyPrint(void) const;

};

// p + v
inline Point3 Point3::operator+(const Vector3 &v) const
{
    return Point3(m_x + v.m_x, m_y + v.m_y, m_z + v.m_z);
}
// p - v
inline Point3 Point3::operator-(const Vector3 &v) const
{
    return Point3(m_x - v.m_x, m_y - v.m_y, m_z - v.m_z);
}
// -p
inline Point3 Point3::operator-() const
{
    return (Point3(-m_x, -m_y, -m_z));
}
// p1 - p2
inline Vector3 Point3::operator-(const Point3 &p2) const
{
    return Vector3(m_x - p2.m_x, m_y - p2.m_y, m_z - p2.m_z);
}
// p * a
inline Point3 Point3::operator*(const double a) const
{
    return Point3(m_x * a, m_y * a, m_z * a);
}
// a * p
Point3 operator*(const double a, const Point3 &p);
inline Point3 operator*(const double a, const Point3 &p)
{
    return Point3(p.m_x * a, p.m_y * a, p.m_z * a);
}

// ||a-b||
inline double Point3::distance(const Point3 &p2) const
{
    return sqrt((m_x - p2.m_x) * (m_x - p2.m_x) +
            (m_y - p2.m_y) * (m_y - p2.m_y) +
            (m_z - p2.m_z) * (m_z - p2.m_z));
}

// ||a-b||^2
inline double Point3::squared_distance(const Point3 &p2) const
{
    return ((m_x - p2.m_x) * (m_x - p2.m_x) +
            (m_y - p2.m_y) * (m_y - p2.m_y) +
            (m_z - p2.m_z) * (m_z - p2.m_z));
}

inline void Point3::prettyPrint(void) const
{
    fprintf(stdout,"[ %f , %f , %f ]\n",m_x,m_y,m_z);
}


#endif