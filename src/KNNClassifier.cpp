#include "KNNClassifier.hpp"

//find the most popular type
KNNClassifier::KNNClassifier(std::vector<Flower> &data) : flowers(data) {
}

std::string KNNClassifier::findMajorityType(std::vector<Flower> &flowers) {
    int array[3] = {0, 0, 0};
    for (auto &flower: flowers) {
        if (flower.getType() == "Iris-setosa") {
            array[0]++;
        } else if (flower.getType() == "Iris-versicolor") {
            array[1]++;
        } else {
            array[2]++;
        }
    }
    //finally, find:
    if (array[0] > array[1]) {
        if (array[0] > array[2]) {
            return "Iris-setosa";
        } else
            return "Iris-virginica";
    } else if (array[1] > array[2]) {
        return "Iris-versicolor";
    } else
        return "Iris-virginica";
}

//get the most popular type
std::string KNNClassifier::classify(const Point &point, int k, DistanceCalculator &dc) {

    //sort the distances' array ----bubble-sort----
    for (int j = 0; j < flowers.size() - 1; j++) {

        // Last i elements are already in place
        for (int l = 0; l < flowers.size() - j - 1; l++) {
            if (dc.calculate(point, flowers[l].getPoint()) >
                dc.calculate(point, flowers[l + 1].getPoint())) {

                Flower temp = flowers[l];
                flowers[l] = flowers[l + 1];
                flowers[l + 1] = temp;

            }
        }
    }
    std::vector<Flower> vec;
    for (int i = 0; i < k; i++) vec.push_back(flowers[i]);

    //now we have a vector of the flowers sort by their distance from our point.
    //we need now to find the most popular type
    return findMajorityType(vec);

}