#include "Algorithms.h"
#include <cmath>
#include <algorithm>

namespace Algorithms {

    static float cross(const Vector& a, const Vector& b) { return a.cross(b); }
    static float dot(const Vector& a, const Vector& b) { return a.dot(b); }

    std::optional<Point> segmentIntersection(const Segment& s1, const Segment& s2) {
        Point a = s1.getA(), b = s1.getB();
        Point c = s2.getA(), d = s2.getB();

        Vector ab(a, b), cd(c, d), ac(a, c);
        float denom = cross(ab, cd);
        if (std::abs(denom) < 1e-6) return std::nullopt; 

        float t = cross(ac, cd) / denom;
        float u = cross(ac, ab) / denom;

        if (t >= 0 && t <= 1 && u >= 0 && u <= 1) {
            return Point(a.getX() + t * ab.getX(), a.getY() + t * ab.getY());
        }
        return std::nullopt;
    }

    std::optional<Point> raySegmentIntersection(const Ray& ray, const Segment& seg) {
        Point r = ray.getStart();
        Vector rd = ray.getDir();
        Point a = seg.getA(), b = seg.getB();
        Vector ab(a, b), ra(r, a);

        float denom = cross(rd, ab);
        if (std::abs(denom) < 1e-6) return std::nullopt;

        float t = cross(ra, ab) / denom;
        float u = cross(ra, rd) / denom;

        if (t >= 0 && u >= 0 && u <= 1) {
            return Point(r.getX() + t * rd.getX(), r.getY() + t * rd.getY());
        }
        return std::nullopt;
    }

    bool pointInPolygon(const Point& p, const Polygon& poly) {
        const auto& verts = poly.getVertices();
        if (verts.size() < 3) return false;

        int count = 0;
        Point rayEnd(p.getX() + 1e5, p.getY());

        for (size_t i = 0; i < verts.size(); ++i) {
            Point a = verts[i], b = verts[(i + 1) % verts.size()];
            Segment edge(a, b);
            if (auto inter = raySegmentIntersection(Ray(p, rayEnd), edge)) {
                if (std::abs(inter->getY() - p.getY()) < 1e-5) {
                    if (inter->getX() > p.getX()) count++;
                } else {
                    count++;
                }
            }
        }
        return count % 2 == 1;
    }

    Point closestPointOnSegment(const Point& p, const Segment& seg) {
        Point a = seg.getA(), b = seg.getB();
        Vector ab(a, b), ap(a, p);
        float len2 = ab.dot(ab);
        if (len2 < 1e-6) return a;

        float t = std::clamp(dot(ap, ab) / len2, 0.0f, 1.0f);
        return Point(a.getX() + t * ab.getX(), a.getY() + t * ab.getY());
    }

    float distanceToSegment(const Point& p, const Segment& seg) {
        Point closest = closestPointOnSegment(p, seg);
        Vector pc(p, closest);
        return pc.length();
    }
}
