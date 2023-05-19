#include "Figure.h"
#include <iostream>
#include <vector>

using namespace std;

class Rectangle : public Figure
{
public:
    Rectangle(double center_x, double center_y, double width, double height) : Figure(center_x, center_y), width_(width), height_(height) {}
    void draw() const
    {
        cout << "R(" << x_center_ << ',' << y_center_ << ")(" << width_ << ',' << height_ << ')';
    }

private:
    double width_, height_;
};

class Circle : public Figure
{
public:
    Circle(double center_x, double center_y, double radius) : Figure(center_x, center_y), radius_(radius) {}
    void draw() const
    {
        cout << "C(" << x_center_ << ',' << y_center_ << ")(" << radius_ << ')';
    }

private:
    double radius_;
};