#ifndef ADVANCEDPROGRAMMING_KNNCLASSIFIER_H
#define ADVANCEDPROGRAMMING_KNNCLASSIFIER_H

#include <string>
#include "Flowers/Flower.hpp"
#include "DistanceCalcs/DistanceCalculator.hpp"
#include "DistanceCalcs/DistanceCalculator.hpp"

class KNNClassifier {

    private:
    std::vector<Flower> flowers; //the data.
        /**
         * @brief get a vector of flowers and find the most popular type
         *
         * @param data
         * @return std::string
         */
        static std::string findMajorityType(std::vector<Flower> &flowers);

    public:

       /**
         * Constructor.
         * @param flowers the vector of the data.
         */
        KNNClassifier(std::vector<Flower> &data);

        /**
         * @brief Get the Knn object - using "findMajorityType" function
         *
         * @param flower
         * @param k
         * @param dc
         * @return std::string
         */
        std::string classify(const Point& point, int k, DistanceCalculator& dc);
     
    };



#endif //ADVANCEDPROGRAMMING_KNNCLASSIFIER_H
