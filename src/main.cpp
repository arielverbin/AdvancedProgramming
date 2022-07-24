#include <iostream>
#include "Point.h"
#include "DistanceCalcs/DistanceCalculator.h"
#include "DistanceCalcs/EuclideanDistance.h"
#include "DistanceCalcs/ManhattanDistance.h"
#include "DistanceCalcs/ChebyshevDistance.h"

void printDistance(DistanceCalculator *dc, Point p1, Point p2);

int main(){
    Point p1 = Point(1,4,0,0);
    Point p2 = Point(10,5,0,0);
    DistanceCalculator* dc = new ChebyshevDistance();
    printDistance(dc, p1, p2);
    return 0;
}

void printDistance(DistanceCalculator* dc, Point p1, Point p2) {
    std::cout << dc->calculate(p1,p2) << std::endl;
}