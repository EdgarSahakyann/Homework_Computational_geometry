#include "Segment.h"
#include <iostream>

Segment::Segment(const Point& a, const Point& b) : m_a(a), m_b(b) {}

bool Segment::onSegment(const Point& p) const {
    Vector ab(m_a, m_b);
    Vector ap(m_a, p);
    if (std::abs(ab.cross(ap)) > 1e-5) return false;
    float dot = ab.dot(ap);
    float len2 = ab.dot(ab);
    return dot >= 0 && dot <= len2;
}

void Segment::show() const {
    std::cout << "Segment: ";
    m_a.show();
    std::cout << " — ";
    m_b.show();
    std::cout << "\n";
}
