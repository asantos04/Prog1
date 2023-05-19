#include "Shape.h"
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Circle : public Shape
{
public:
    Circle(const point &center, double radius) : Shape(center), radius_(radius) {}
    double area() const
    {
        return M_PI * radius_ * radius_;
    }
    double perimeter() const
    {
        return 2 * M_PI * radius_;
    }
    bool contains(const point &p) const
    {
        return (sqrt(pow(p.x - get_center().x, 2) + pow(p.y - get_center().y, 2)) <= radius_);
    }

private:
    double radius_;
};
class Rectangle : public Shape
{
public:
    Rectangle(const point &center, double width, double height) : Shape(center), height_(height), width_(width) {}
    double area() const
    {
        return height_ * width_;
    }
    double perimeter() const
    {
        return 2 * (height_ + width_);
    }
    bool contains(const point &p) const
    {
        double left = get_center().x - width_ / 2;
        double right = get_center().x + width_ / 2;
        double bottom = get_center().y - height_ / 2;
        double top = get_center().y + height_ / 2;

        return p.x >= left && p.x <= right && p.y >= bottom && p.y <= top;
    }

private:
    double height_;
    double width_;
};