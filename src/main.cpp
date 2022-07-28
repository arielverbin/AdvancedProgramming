#include <iostream>
#include "Point.h"
#include "DistanceCalcs/DistanceCalculator.h"
#include "DistanceCalcs/EuclideanDistance.h"
#include "DistanceCalcs/ManhattanDistance.h"
#include "DistanceCalcs/ChebyshevDistance.h"
#include "Flowers/Flower.h"
#include <string>
void printDistance(DistanceCalculator *dc, Point p1, Point p2);
/**
 * tests.
 * @return 0;
 */
int main(){

    printDistance(new EuclideanDistance(), p,p2);
    return 0;
}
//test for the distance methods.
void printDistance(DistanceCalculator* dc, Point p1, Point p2) {
    std::cout << dc->calculate(p1,p2) << std::endl;
}