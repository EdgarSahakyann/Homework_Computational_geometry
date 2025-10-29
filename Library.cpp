#pragma once

#include "Point.h"
#include "Vector.h"
#include "Line.h"
#include "Segment.h"
#include "Ray.h"
#include "Polygon.h"
#include <memory>

class Library {
public:
    static std::unique_ptr<Point> createPoint(float x, float y) {
        return std::make_unique<Point>(x, y);
    }

    static std::unique_ptr<Vector> createVector(float x, float y) {
        return std::make_unique<Vector>(x, y);
    }

    static std::unique_ptr<Line> createLine(const Point& a, const Point& b) {
        return std::make_unique<Line>(a, b);
    }

    static std::unique_ptr<Segment> createSegment(const Point& a, const Point& b) {
        return std::make_unique<Segment>(a, b);
    }

    static std::unique_ptr<Ray> createRay(const Point& start, const Point& dir) {
        return std::make_unique<Ray>(start, dir);
    }

    static std::unique_ptr<Polygon> createPolygon(const std::vector<Point>& verts) {
        return std::make_unique<Polygon>(verts);
    }
};
