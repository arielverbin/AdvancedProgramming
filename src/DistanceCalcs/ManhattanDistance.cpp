
#include "ManhattanDistance.h"
#include <cmath>
#include <stdexcept>

double ManhattanDistance::calculate(Point p1, Point p2) {
    if(p1.getLength() != p2.getLength()) {
        throw std::invalid_argument("The two points must have the same size.");
    }
    double sum = 0;
    for(int i = 0; i < p1.getLength(); i ++) {
            sum += std::abs(p1.get(i) - p2.get(i));
    }
    return sum;
}