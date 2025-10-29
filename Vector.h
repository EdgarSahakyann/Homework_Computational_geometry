#pragma once
#include "Point.h"
#include <cmath>

class Vector {
public:
    Vector(float x = 0, float y = 0);
    Vector(const Point& from, const Point& to);

    float getX() const;
    float getY() const;
    float length() const;
    void normalize();
    void show() const;

    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator*(float scalar) const;
    float dot(const Vector& other) const;
    float cross(const Vector& other) const;

private:
    float m_x;
    float m_y;
};
