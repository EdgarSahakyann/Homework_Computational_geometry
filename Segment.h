#pragma once
#include "Point.h"
#include "Vector.h"

class Segment {
public:
    Segment(const Point& a, const Point& b);
    bool onSegment(const Point& p) const;
    void show() const;
    
    const Point& getA() const { return m_a; }
    const Point& getB() const { return m_b; }

private:
    Point m_a, m_b;
};
