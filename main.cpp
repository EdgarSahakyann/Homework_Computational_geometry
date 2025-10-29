#include "Library.hpp"
#include "Algorithms.hpp"
#include <iostream>

int main() {
    auto A = Library::createPoint(0, 0);
    auto B = Library::createPoint(3, 3);
    auto C = Library::createPoint(3, 0);
    auto D = Library::createPoint(1, 1);

    auto v = Library::createVector(3, 3);
    v->show();
    std::cout << " length = " << v->length() << "\n";

    auto line = Library::createLine(*A, *B);
    line->show();
    std::cout << "Point "; C->show();
    std::cout << (line->onLine(*C) ? " on line\n" : " not on line\n");

    auto seg = Library::createSegment(*A, *B);
    seg->show();
    std::cout << "Point "; C->show();
    std::cout << (seg->onSegment(*C) ? " on segment\n" : " not on segment\n");

    auto ray = Library::createRay(*A, *B);
    ray->show();
    std::cout << (ray->onRay(*C) ? "Point on ray\n" : "Point not on ray\n");

    auto poly = Library::createPolygon({{0,0}, {4,0}, {4,4}, {0,4}});
    poly->show();
    std::cout << "Convex: " << (poly->isConvex() ? "Yes" : "No") << "\n";

    Segment s1(*A, *C), s2(*D, Point(4, 1));
    if (auto inter = Algorithms::segmentIntersection(s1, s2)) {
        std::cout << "Segments intersect at "; inter->show(); std::cout << "\n";
    } else {
        std::cout << "Segments do not intersect\n";
    }

    std::cout << "Point "; D->show();
    std::cout << " in polygon: " << (Algorithms::pointInPolygon(*D, *poly) ? "Yes" : "No") << "\n";

    return 0;
}
