#include <iostream>
#include <string> // for string class
#include"Point.h"

//A Flower - a Point + type
class Flower {
    private:
        //the flower's data
        Point point;
        //the flower's type
        std::string type;
    public:
    Flower(Point point, std::string type);
    /**
     * @brief Get the Point object
     * 
     * @return Point 
     */
    Point getPoint();

    /**
     * @brief 
     * @return std::string
     */
    std::string getType();

};