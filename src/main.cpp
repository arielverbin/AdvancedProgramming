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
    Point p1 = Point(1,4,0,0);
    Point p2 = Point(10,5,0,0);
    p2 = p1;
    std::cout << p2.getX1() << p2.getX2() <<std::endl;
    DistanceCalculator* dc = new ChebyshevDistance();
    printDistance(dc, p1, p2);
    Flower f = Flower(p1, "iris");
    std::cout << f.getPoint().getX1() << std::endl;
    std::cout << f.getType() << std::endl;

    return 0;
}
//test for the distance methods.
void printDistance(DistanceCalculator* dc, Point p1, Point p2) {
    std::cout << dc->calculate(p1,p2) << std::endl;
}