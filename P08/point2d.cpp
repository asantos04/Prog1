#include <iostream>
#include "Point2d.h"
#include <cmath>

void Point2d::translate(const Point2d& t) {
    x += t.x;
    y += t.y;
}

double Point2d::distance_to(const Point2d& p) const {
    double dx = x - p.x;
    double dy = y - p.y;
    return sqrt(dx*dx + dy*dy);
}