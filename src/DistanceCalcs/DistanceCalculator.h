//
// Created by Ariel Verbin on 24/07/2022.
//

#ifndef ADVANCEDPROGRAMMING_DISTANCECALCULATOR_H
#define ADVANCEDPROGRAMMING_DISTANCECALCULATOR_H

#include "../Point.h"
class DistanceCalculator {
public:
    virtual double calculate(Point p1, Point p2) = 0;
};


#endif //ADVANCEDPROGRAMMING_DISTANCECALCULATOR_H
