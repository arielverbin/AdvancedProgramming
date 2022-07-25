
#include "DistanceCalculator.h"
#include <vector>
Point *DistanceCalculator::findKNearest(Point p, Point* data, int dataLength, int k) {
    auto* lengths = new double[dataLength];
    for(int i = 0; i < dataLength; i ++) {
      //  lengths[i] = DistanceCalculator::calculate(p, data[i]);
    }
    partition(lengths, k);

    return nullptr;
}

void DistanceCalculator::partition(double *lengths, int k) {
}

