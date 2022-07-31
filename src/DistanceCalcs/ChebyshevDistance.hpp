
#ifndef ADVANCEDPROGRAMMING_CHEBYSHEVDISTANCE_H
#define ADVANCEDPROGRAMMING_CHEBYSHEVDISTANCE_H


#include "DistanceCalculator.hpp"
/**
 * Distance Calculator using Chebyshev formula, which is d(p1,p2):=max{|p1.xi-p2.xi|} i=1,...,n.
 */
class ChebyshevDistance : public DistanceCalculator{
public:
    double calculate(const Point &p1, const Point &p2) override;
};


#endif //ADVANCEDPROGRAMMING_CHEBYSHEVDISTANCE_H
