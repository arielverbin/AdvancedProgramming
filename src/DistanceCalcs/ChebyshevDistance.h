
#ifndef ADVANCEDPROGRAMMING_CHEBYSHEVDISTANCE_H
#define ADVANCEDPROGRAMMING_CHEBYSHEVDISTANCE_H


#include "DistanceCalculator.h"
/**
 * Distance Calculator using Chebyshev formula, which is d(p1,p2):=max{|p1.xi-p2.xi|} i=1,...,n.
 */
class ChebyshevDistance : public DistanceCalculator{
public:
    double calculate(Point p1, Point p2) override;
};


#endif //ADVANCEDPROGRAMMING_CHEBYSHEVDISTANCE_H
