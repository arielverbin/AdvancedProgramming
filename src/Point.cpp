#include "Point.h"

Point::Point(double* data, int length){
    this->data = data;
    this->length = length;
}

double Point::get(int i) const {
    return this->data[i];
}

int Point::getLength() const {
    return this->length;
}
std::ostream& operator<<(std::ostream& os, const Point& a){
    os<<"(";
    for(int i = 0; i < a.getLength() - 1; i ++) {
        os<<a.get(0) <<", ";
    }
    os << a.get(a.getLength() - 1) << ")";
    return os;
}



