#pragma once
#include <vector>
#include "Point.h"
#include "Vector.h"

class Polygon {
public:
    Polygon(const std::vector<Point>& vertices);
    void show() const;
    bool isConvex() const;
    const std::vector<Point>& getVertices() const;

private:
    std::vector<Point> m_vertices;
};
