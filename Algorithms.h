#pragma once
#include "Point.h"
#include "Vector.h"
#include "Line.h"
#include "Segment.h"
#include "Ray.h"
#include "Polygon.h"

#include <optional>

namespace Algorithms {
    std::optional<Point> segmentIntersection(const Segment& s1, const Segment& s2);

    std::optional<Point> raySegmentIntersection(const Ray& ray, const Segment& seg);

    bool pointInPolygon(const Point& p, const Polygon& poly);

    float distanceToSegment(const Point& p, const Segment& seg);

    Point closestPointOnSegment(const Point& p, const Segment& seg);
}
