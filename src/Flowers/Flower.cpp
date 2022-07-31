#include "Flower.hpp"
#include <utility>
#include <iostream>
#include <string>

//constructor - from point and string
Flower::Flower(Point &point1, std::string name) :
                    point(point1), type(std::move(name)) { }

Flower::Flower(const std::string &str) : point(std::vector<double>{0}){
    std::vector<double> values;
    int start = 0;
    int end = (int)str.find(',');
    int i = 0;
    while (end != -1) {
        values.emplace_back(std::stod(str.substr(start, end - start)));
        i++;
        start = end + 1;
        end = (int)str.find(',', start);
    }
    point = Point(values);
    type =str.substr(start, end - start);
}


Point& Flower::getPoint(){
    return point;
}

std::string& Flower::getType(){
    return type;
}
std::ostream& operator<<(std::ostream& os, Flower& a){
    os << "[" << a.getPoint() << ", " << a.getType() << "]";
    return os;
}
