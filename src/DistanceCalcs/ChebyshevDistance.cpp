
#include <iostream>
#include <cmath>
#include "ChebyshevDistance.hpp"
double ChebyshevDistance::calculate(const Point &p1, const Point &p2) {
    if(p1.getLength() != p2.getLength()) {
        std::cout << "The two points must have the same size."<< std::endl;
        return -1;
    }
    double max = 0;
    for(int i = 0; i < p1.getLength(); i ++) {
        if(std::abs(p1.get(i) - p2.get(i))>max) {
            max = std::abs(p1.get(i) - p2.get(i));
        }
    }
    return max;
}