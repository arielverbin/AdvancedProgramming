#ifndef ADVANCEDPROGRAMMING_POINT_H
#define ADVANCEDPROGRAMMING_POINT_H

//A four-dimensional point.
class Point {
    private:
        double x1;
        double x2;
        double x3;
        double x4;
    public:
    Point(double x1, double x2, double x3, double x4);
    /**
     * @return the first value of the point.
     **/
    double getX1() const;
    /**
     * @return the second value of the point.
     **/
    double getX2() const;
    /**
     * @return the third value of the point.
     **/
    double getX3() const;
    /**
     * @return the forth value of the point.
     **/
    double getX4() const;
    Point& operator=(const Point& other);
};
#endif //ADVANCEDPROGRAMMING_POINT_H
