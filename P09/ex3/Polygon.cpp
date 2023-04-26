#include <iostream>
#include <cmath>
#include "Polygon.h"

double distance(const Point& a, const Point& b)
{
    return sqrt(pow(a.get_x() - b.get_x(), 2) + pow(a.get_y() - b.get_y(), 2));
}

Polygon::Polygon()
{
    vertices = {};
}

Polygon::Polygon(std::vector<Point> v)
{
    vertices = v;
}

bool Polygon::get_vertex(int n, Point& p) const
{
    if (n > 0 && (unsigned long) n <= vertices.size())
    {
        p = vertices[n-1];
        return true;
    }
    return false;
}

void Polygon::add_vertex(int n, const Point& p)
{
    vertices.insert(vertices.begin() + n - 1, p);
}

void Polygon::show() const
{
    std::cout << '{';
    for (Point p: vertices) p.show();
    std::cout << '}';
}

float Polygon::perimeter() const
{
    if (vertices.size() >= 3)
    {
        double sum = distance(vertices[0],vertices[vertices.size() - 1]);
        for (unsigned long i = 0; i < vertices.size() - 1; ++i) sum += distance(vertices[i], vertices[i+1]);
        return sum;
    }
    return 0;
}