#ifndef Point2_H
#define Point2_H

#include <cstdio>

class Point2
{

public:
    double m_x;
    double m_y;

    // default constructor
    Point2(void);
    // constructor
    Point2(const double a);
    // constructor
    Point2(const double x, const double y);
    // copy constructor
    Point2(const Point2 &v);
    // deconstructor
    ~Point2();
    
    Point2 operator*(const double a) const;    // p * a
    Point2 &operator=(const Point2 &rhs);      // assignment operator
    void prettyPrint(void) const;

};

// p * a
inline Point2 Point2::operator*(const double a) const
{
    return Point2(m_x * a, m_y * a);
}
// a * p
Point2 operator*(const double a, const Point2 &p);
inline Point2 operator*(const double a, const Point2 &p)
{
    return Point2(p.m_x * a, p.m_y * a);
}

inline void Point2::prettyPrint(void) const
{
    fprintf(stdout,"[ %f , %f ]\n",m_x,m_y);
}


#endif