
#ifndef ADVANCEDPROGRAMMING_DISTANCECALCULATOR_H
#define ADVANCEDPROGRAMMING_DISTANCECALCULATOR_H

#include "../Point.hpp"
/**
 * A DistanceCalculator can calculate the distance between 2 Points, using an virtual formula.
 * It can also return the K-nearest points from a given point out of an array of data.
 */
class DistanceCalculator {
public:
    virtual double calculate(Point p1, Point p2) = 0;
};


#endif //ADVANCEDPROGRAMMING_DISTANCECALCULATOR_H
