#include "Point.h"

Point::Point(double y1, double y2, double y3, double y4) :
        x1(y1), x2(y2), x3(y3), x4(y4) {}

Point::Point():
     x1(0), x2(0), x3(0), x4(0) {}


double Point::getX1() const {
    return x1;
}

double Point::getX2() const {
    return x2;
}

double Point::getX3() const {
    return x3;
}

double Point::getX4() const {
    return x4;
}

Point& Point::operator=(const Point &other) {
    this->x1 = other.getX1();
    this->x2 = other.getX2();
    this->x3 = other.getX3();
    this->x4 = other.getX4();
    return *this;
}


