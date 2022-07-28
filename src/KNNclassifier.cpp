#include "KNNClassifier.h"
//find the most popular type
KNNClassifier::KNNClassifier(Flower** data, int size){
    length = size;
    flowers = data;
}

std::string KNNClassifier::findMajorityType(Flower** flowers, int length){
    int array[3] = {0,0,0};
    for (int i = 0; i < length; i++){
        if (flowers[i]->getType()=="Iris-setosa"){
            array[0]++;
        }
        else if (flowers[i]->getType()=="Iris-versicolor"){
            array[1]++;
        }
        else{
            array[2]++;
        }
    }
    //finally, find:
    if (array[0] > array[1]){
        if (array[0] > array[2]){
            return "Iris-setosa";
        }
        else
            return "Iris-virginica";
    }
    else if (array[1] > array[2])
    {
        return "Iris-versicolor";
    }
    else
        return "Iris-virginica";
}

//get the majority type
std::string KNNClassifier::classify(Point point, int k, DistanceCalculator& dc){

    //sort the distances' array ----bubble-sort---- efficiency doesn't important
    for (int j = 0; j < length - 1; j++){

        // Last i elements are already 
        // in place
        for (int l = 0; l < length - j - 1; l++){
            if (dc.calculate(point, flowers[l]->getPoint()) >
                        dc.calculate(point, flowers[l+1]->getPoint())){
                Flower* temp = flowers[l];
                flowers[l] = flowers[l+1];
                flowers[l+1] = temp;
            }
        }
    }

    //now we have an array of the flowers sort by their distance from our point.
    //we need now to find the most popular type
    return findMajorityType(flowers,k);

}