#ifndef POINT_H
#define POINT_H

class Point
{
    private:
        int x_,y_;
    public:
        Point();
        Point(int x, int y);
        int get_x() const;
        int get_y() const;
        void show() const;
};

#endif