#ifndef ADVANCEDPROGRAMMING_POINT_H
#define ADVANCEDPROGRAMMING_POINT_H

#include <iostream>

//A four-dimensional point.
class Point {
    private:
        double* data;
        int length;
    public:
    /**
     * Constructor.
     * @param data a dynamic array of double values.
     * @param length the length of the array.
     */
    Point(double *data, int length);

    /**
     * @param i, the index of the value.
     * @return the value in the i-th place.
     **/
    double get(int i) const;
    /**
     * @return the number of double values.
     */
    int getLength() const;

    /**
     * Overloading the << operator.
     * @param os the output stream.
     * @param a the point,
     * @return the output stream with the addition of Point.
     */
    friend std::ostream& operator<<(std::ostream& os, const Point& a);
};

#endif //ADVANCEDPROGRAMMING_POINT_H
