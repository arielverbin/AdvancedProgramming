//
// Created by Ariel Verbin on 25/07/2022.
//

#include "ManhattanDistance.h"
#include <cmath>

double ManhattanDistance::calculate(Point p1, Point p2) {
    double sum = std::abs(p1.getX1()-p2.getX1());
    sum += std::abs(p1.getX2()-p2.getX2());
    sum += std::abs(p1.getX3()-p2.getX3());
    sum += std::abs(p1.getX4()-p2.getX4());
    return sum;
}