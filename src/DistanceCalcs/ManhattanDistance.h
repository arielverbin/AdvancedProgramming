//
// Created by Ariel Verbin on 25/07/2022.
//

#ifndef ADVANCEDPROGRAMMING_MANHATTANDISTANCE_H
#define ADVANCEDPROGRAMMING_MANHATTANDISTANCE_H


#include "DistanceCalculator.h"
/**
 * Distance Calculator using Manhattan formula, which is d(p1,p2):=sum|p1.xi-p2.xi| i=1,...,n.
 */
class ManhattanDistance : public DistanceCalculator {
public:
    double calculate(Point p1, Point p2) override;
};


#endif //ADVANCEDPROGRAMMING_MANHATTANDISTANCE_H
