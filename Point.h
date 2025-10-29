#pragma once
#include <iostream>

class Point {
public:
    Point(float x, float y);
    float getX() const;
    float getY() const;
    void show() const;

private:
    float m_x;
    float m_y;
};
