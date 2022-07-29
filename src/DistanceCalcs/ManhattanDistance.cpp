
#include "ManhattanDistance.hpp"
#include <cmath>
#include <stdexcept>

double ManhattanDistance::calculate(Point p1, Point p2) {
    if(p1.getLength() != p2.getLength()) {
        std::cout << "The two points must have the same size."<< std::endl;
        return -1;
    }
    double sum = 0;
    for(int i = 0; i < p1.getLength(); i ++) {
            sum += std::abs(p1.get(i) - p2.get(i));
    }
    return sum;
}