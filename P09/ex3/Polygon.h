#include <vector>
#include <cstddef>
#include "Point.h"
#ifndef POLYGON_H
#define POLYGON_H

class Polygon
{
    private:
        std::vector<Point> vertices;
    public:
        Polygon();
        Polygon(std::vector<Point> v);
        void show() const;
        bool get_vertex(int n, Point& p) const;
        void add_vertex(int n, const Point& p);
        float perimeter() const;
};

#endif