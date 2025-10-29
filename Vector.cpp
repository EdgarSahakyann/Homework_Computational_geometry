#include "Vector.h"
#include <iostream>

Vector::Vector(float x, float y) : m_x(x), m_y(y) {}

Vector::Vector(const Point& from, const Point& to)
    : m_x(to.getX() - from.getX()), m_y(to.getY() - from.getY()) {}

float Vector::getX() const { return m_x; }
float Vector::getY() const { return m_y; }

float Vector::length() const {
    return std::sqrt(m_x * m_x + m_y * m_y);
}

void Vector::normalize() {
    float len = length();
    if (len > 1e-6) {
        m_x /= len;
        m_y /= len;
    }
}

Vector Vector::operator+(const Vector& other) const {
    return Vector(m_x + other.m_x, m_y + other.m_y);
}

Vector Vector::operator-(const Vector& other) const {
    return Vector(m_x - other.m_x, m_y - other.m_y);
}

Vector Vector::operator*(float scalar) const {
    return Vector(m_x * scalar, m_y * scalar);
}

float Vector::dot(const Vector& other) const {
    return m_x * other.m_x + m_y * other.m_y;
}

float Vector::cross(const Vector& other) const {
    return m_x * other.m_y - m_y * other.m_x;
}

void Vector::show() const {
    std::cout << "<" << m_x << ", " << m_y << ">";
}
