#ifndef ADVANCEDPROGRAMMING_POINT_H
#define ADVANCEDPROGRAMMING_POINT_H

//A four-dimensional point.
class Point {
    private:
        const double x1;
        const double x2;
        const double x3;
        const double x4;
    public:
    Point(double x1, double x2, double x3, double x4);
    /**
     * @return the first value of the point.
     **/
    double getX1();
    /**
     * @return the second value of the point.
     **/
    double getX2();
    /**
     * @return the third value of the point.
     **/
    double getX3();
    /**
     * @return the forth value of the point.
     **/
    double getX4();
};
#endif //ADVANCEDPROGRAMMING_POINT_H
