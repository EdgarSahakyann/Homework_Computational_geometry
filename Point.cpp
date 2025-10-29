#include "Point.hpp"
#include <iostream>

Point::Point(float x, float y) : m_x(x), m_y(y) {}

float Point::getX() const { return m_x; }
float Point::getY() const { return m_y; }

void Point::show() const {
    std::cout << "(" << m_x << ", " << m_y << ")";
}
