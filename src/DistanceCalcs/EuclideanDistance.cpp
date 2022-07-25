
#include <cmath>
#include "EuclideanDistance.h"

double EuclideanDistance::calculate(Point p1, Point p2) {
    double sum = std::pow(p1.getX1() - p2.getX1(), 2);
    sum += std::pow(p1.getX2() - p2.getX2(), 2);
    sum += std::pow(p1.getX3() - p2.getX3(), 2);
    sum += std::pow(p1.getX4() - p2.getX4(), 2);
    return std::sqrt(sum);
}