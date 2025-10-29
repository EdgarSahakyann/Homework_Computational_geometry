#pragma once
#include "Point.hpp"
#include "Vector.hpp"

class Line {
public:
    Line(const Point& p, const Vector& v);
    Line(const Point& a, const Point& b);

    bool onLine(const Point& p) const;
    void show() const;

private:
    Point m_point;
    Vector m_dir;
};
