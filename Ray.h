#pragma once
#include "Point.hpp"
#include "Vector.hpp"

class Ray {
public:
    Ray(const Point& start, const Point& direction);
    Ray(const Point& start, const Vector& dir);

    bool onRay(const Point& p) const;
    void show() const;

    const Point& getStart() const { return m_start; }
    const Vector& getDir() const { return m_dir; }

private:
    Point m_start;
    Vector m_dir;
};
