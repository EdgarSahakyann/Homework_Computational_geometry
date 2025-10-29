#include "Line.h"
#include <iostream>
#include <cmath>

Line::Line(const Point& p, const Vector& v) : m_point(p), m_dir(v) {
    if (std::abs(m_dir.length()) < 1e-6) {
        m_dir = Vector(1, 0); // защита
    }
}

Line::Line(const Point& a, const Point& b) : m_point(a), m_dir(a, b) {
    if (std::abs(m_dir.length()) < 1e-6) {
        m_dir = Vector(1, 0);
    }
}

bool Line::onLine(const Point& p) const {
    Vector ap(m_point, p);
    return std::abs(m_dir.cross(ap)) < 1e-5;
}

void Line::show() const {
    std::cout << "Line: ";
    m_point.show();
    std::cout << " + t * ";
    m_dir.show();
    std::cout << "\n";
}
