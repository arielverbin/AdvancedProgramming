#include "Flower.h"
#include <utility>

//constructor - from point and string
Flower::Flower(Point point1, std::string name) :
                    point(point1), type(std::move(name)) { }


Point& Flower::getPoint(){
    return point;
}

std::string& Flower::getType(){
    return type;
}
