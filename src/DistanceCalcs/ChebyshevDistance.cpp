//
// Created by Ariel Verbin on 25/07/2022.
//
#include <iostream>
#include <cmath>
#include "ChebyshevDistance.h"
double ChebyshevDistance::calculate(Point p1, Point p2) {
    double max = std::abs(p1.getX1() - p2.getX1());
    max < std::abs(p1.getX2() - p2.getX2()) ? max = std::abs(p1.getX2() - p2.getX2()) : max;
    max < std::abs(p1.getX3() - p2.getX3()) ? max = std::abs(p1.getX3() - p2.getX3()) : max;
    max < std::abs(p1.getX4() - p2.getX4()) ? max = std::abs(p1.getX4() - p2.getX4()) : max;
    return max;
}