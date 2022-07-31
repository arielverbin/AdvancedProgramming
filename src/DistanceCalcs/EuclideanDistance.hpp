
#ifndef ADVANCEDPROGRAMMING_EUCLIDEANDISTANCE_H
#define ADVANCEDPROGRAMMING_EUCLIDEANDISTANCE_H

#include "DistanceCalculator.hpp"

/**
 * Distance Calculator using Euclidean formula, which is d(p1,p2):=sqrt(sum((p1.xi-p2.xi)^2)) i=1,...,n.
 **/
class EuclideanDistance : public DistanceCalculator {
public:
    double calculate(const Point &p1, const Point &p2) override;
};


#endif //ADVANCEDPROGRAMMING_EUCLIDEANDISTANCE_H
