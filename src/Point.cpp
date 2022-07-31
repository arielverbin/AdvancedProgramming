#include "Point.hpp"

#include <utility>

Point::Point(std::vector<double> d) : data(std::move(d)){
}
Point::Point(const std::string& str) {
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
    values.emplace_back(std::stod(str.substr(start, end - start)));
    data = values;
}
double Point::get(int i) const {
    return data[i];
}

int Point::getLength() const {
    return (int)data.size();
}
std::ostream& operator<<(std::ostream& os, const Point& a){
    os<<"(";
    for(int i = 0; i < a.getLength() - 1; i ++) {
        os<<a.get(i) <<", ";
    }
    os << a.get(a.getLength() - 1) << ")";
    return os;
}



