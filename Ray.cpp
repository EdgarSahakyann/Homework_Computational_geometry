#include "Ray.h"
#include <iostream>
#include <cmath>

Ray::Ray(const Point& start, const Point& direction)
    : m_start(start), m_dir(start, direction) {
    if (std::abs(m_dir.length()) < 1e-6) m_dir = Vector(1, 0);
}

Ray::Ray(const Point& start, const Vector& dir)
    : m_start(start), m_dir(dir) {
    if (std::abs(m_dir.length()) < 1e-6) m_dir = Vector(1, 0);
}

bool Ray::onRay(const Point& p) const {
    Vector sp(m_start, p);
    if (std::abs(m_dir.cross(sp)) > 1e-5) return false;

    float dot = m_dir.dot(sp);
    return dot >= 0;
}

void Ray::show() const {
    std::cout << "Ray: ";
    m_start.show();
    std::cout << " → ";
    Point end_point(m_start.getX() + m_dir.getX(), m_start.getY() + m_dir.getY());
    end_point.show();
    std::cout << "\n";
}
