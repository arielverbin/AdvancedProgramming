#include "Point.h"

Point::Point(double* data, int length) : data(data), length(length){

}
double Point::get(int i) const {
    return data[i];
}

int Point::getLength() const {
    return length;
}
std::ostream& operator<<(std::ostream& os, const Point& a){
    os<<"(";
    for(int i = 0; i < a.getLength() - 1; i ++) {
        os<<a.get(i) <<", ";
    }
    os << a.get(a.getLength() - 1) << ")";
    return os;
}



