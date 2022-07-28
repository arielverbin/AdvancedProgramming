#include "Point.h"

Point::Point(double* data, int length) : data(data), length(length){
}
Point::Point(const std::string& str, int numOfValues) : data(nullptr){
    auto* values = new double[numOfValues];
    int start = 0;
    int end = (int)str.find(',');
    int i = 0;
    while (end != -1) {
        values[i]=std::stod(str.substr(start, end - start));
        i++;
        start = end + 1;
        end = (int)str.find(',', start);
    }
    values[i] = std::stod(str.substr(start, end - start));
    data = values;
    length = numOfValues;
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



