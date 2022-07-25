#include "Flower.h"
#include <utility>

//constructor - from point and string
Flower::Flower(Point point1, std::string name) :
                    point(point1), type(std::move(name)) { }

/**
 * @brief get the flower's point
 * 
 * @return Point 
 */
Point& Flower::getPoint(){
    return point;
}
/**
 * @brief get the flower's type
 * 
 * @return std::string 
 */
std::string& Flower::getType(){
    return type;
}
