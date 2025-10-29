#include "Polygon.hpp"
#include <iostream>

Polygon::Polygon(const std::vector<Point>& vertices) : m_vertices(vertices) {}

void Polygon::show() const {
    std::cout << "Polygon: ";
    for (const auto& p : m_vertices) {
        p.show();
        std::cout << " ";
    }
    std::cout << "\n";
}

bool Polygon::isConvex() const {
    if (m_vertices.size() < 3) return false;
    bool positive = false;
    size_t n = m_vertices.size();

    for (size_t i = 0; i < n; ++i) {
        const Point& a = m_vertices[i];
        const Point& b = m_vertices[(i + 1) % n];
        const Point& c = m_vertices[(i + 2) % n];

        Vector ab(a, b), bc(b, c);
        float cross = ab.cross(bc);

        if (i == 0) {
            positive = cross > 0;
        } else if ((cross > 0) != positive && std::abs(cross) > 1e-5) {
            return false;
        }
    }
    return true;
}

const std::vector<Point>& Polygon::getVertices() const { return m_vertices; }
