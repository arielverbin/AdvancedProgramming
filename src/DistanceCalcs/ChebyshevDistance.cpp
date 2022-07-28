
#include <iostream>
#include <cmath>
#include "ChebyshevDistance.h"
double ChebyshevDistance::calculate(Point p1, Point p2) {
    if(p1.getLength() != p2.getLength()) {
        throw std::invalid_argument("The two points must have the same size.");
    }
    double max = 0;
    for(int i = 0; i < p1.getLength(); i ++) {
        if(std::abs(p1.get(i) - p2.get(i))>max) {
            max = std::abs(p1.get(i) - p2.get(i));
        }
    }
    return max;
}