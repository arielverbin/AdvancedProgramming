#ifndef ADVANCEDPROGRAMMING_KNNCLASSIFIER_H
#define ADVANCEDPROGRAMMING_KNNCLASSIFIER_H

#include <string>
#include "Flowers/Flower.h"
#include "DistanceCalcs/DistanceCalculator.h"
#include "DistanceCalcs/DistanceCalculator.h"

class KNNClassifier {
    public:
        /**
         * @brief Get the Knn object - using "findMajorityType" function
         *
         * @param flower
         * @param k
         * @param dc
         * @return std::string
         */
        std::string classify(Point point, int k, DistanceCalculator& dc);
        /**
         * Constructor.
         * @param flowers the array of data.
         * @param length its length.
         */
        KNNClassifier(Flower** flowers, int length);

    private:
    Flower** flowers; //the data.
    int length; //its length
        /**
         * @brief get a array of flowers and find the most popular type
         *
         * @param data
         * @param length
         * @return std::string
         */
        static std::string findMajorityType(Flower** data, int length);
    };



#endif //ADVANCEDPROGRAMMING_KNNCLASSIFIER_H
