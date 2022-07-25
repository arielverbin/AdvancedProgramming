#include "Flower.h"
//constructor - from point and string
Flower::Flower(Point const point1, std::string type) {
    this->point = point1;
}

/**
 * @brief get the flower's point
 * 
 * @return Point 
 */
Point Flower::getPoint(){
    return point;
}
/**
 * @brief get the flower's type
 * 
 * @return std::string 
 */
std::string Flower::getType(){
    return type;
}
