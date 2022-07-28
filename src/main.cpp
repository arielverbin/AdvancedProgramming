#include <iostream>
#include "Point.h"
#include "Flowers/Flower.h"
#include "KNNClassifier.h"
#include "DistanceCalcs/ManhattanDistance.h"
#include "DistanceCalcs/EuclideanDistance.h"
#include "DistanceCalcs/ChebyshevDistance.h"
#include <fstream>
#include<list>

using namespace std;
/**
 * Converts a list to an array.
 * @param l the list.
 * @return  the new array.
 */
void** listToArray(const list<void*>& l) {
    void** newArr = new void*[l.size()];
    int i = 0;
    for(void* v : l) {
        newArr[i++] = v;
    }
    return newArr;
}
/**
 * opens a file.
 * @param fileName the path.
 * @return the ifstream.
 */
ifstream openFile(const std::string& fileName) {
    ifstream input;
    input.open(fileName);
    if (input.fail()) {
        cout << "Could not open " << fileName << endl;
        exit(1);
    }
    return input;
}
/**
 * Creates a new array with the flowers from the given file.
 * @param fileName the given file.
 * @param length pointer to int, used to store the number of flowers in the file.
 * @return the array.
 */
Flower** getDataFromFile(const std::string &fileName, int *length) {
    list<void *> l;
    string line;
    ifstream input = openFile(fileName);
    while (!input.eof()) {
        getline(input, line);
        if(std::equal(line.begin(), line.end(), "")) continue; // avoid an empty line.
        l.push_back(new Flower(line, 4));
    }
    *length = (int)l.size();
    return (Flower**)listToArray(l);
}
/**
 * Creates a new array with the points (unclassified flowers) from the given file.
 * @param fileName the given file.
 * @param length pointer to int, used to store the number of points in the file.
 * @return the array.
 */
Point** getPointsFromFile(const std::string& fileName, int *length){
    list<void *> l;
    string line;
    ifstream input = openFile(fileName);
    while (!input.eof()) {
        getline(input, line);
        if(std::equal(line.begin(), line.end(), "")) continue; // avoid an empty line.
        l.push_back(new Point(line,4));
    }
    *length = (int)l.size();
    return (Point**)listToArray(l);
}
/**
 * Copy the classified points to a given file.
 * @param fileName the file.
 * @param flowers the classified points (as flowers)
 * @param length the length of the flowers array.
 */
void copyToFile(const std::string& fileName, Flower** flowers, int length) {
    ofstream output;
    output.open (fileName);
    for(int i = 0; i < length; i ++) {
        output << flowers[i]->getType() << endl;
    }
    output.close();
}
/**
 * classify all of the points according to the given classifier, distance calculator, and k.
 * @param dc the distance calculator.
 * @param knn the classifier.
 * @param unclassifiedPoints the points to be classified.
 * @param lengthOfPoints the number of points to be classified.
 * @param k the constant k from the algorithm.
 * @return new array of classified points (as flowers).
 */
Flower** classifyAll(DistanceCalculator *dc, KNNClassifier knn,
                     Point** unclassifiedPoints, int lengthOfPoints, int k) {
    auto** classifiedPoints = new Flower*[lengthOfPoints]; //to be filled with the classified points.
    for(int i = 0; i < lengthOfPoints; i ++) {
        Point curPoint = *unclassifiedPoints[i]; //take the current point.
        classifiedPoints[i] = new Flower(curPoint, //classify it and create a new flower.
                                         knn.classify(curPoint,k, *dc));
    }
    return classifiedPoints;
}

/**
 * ?!?!#??
 */
int main() {
    int k = 11;
    //length of classified flowers, length of unclassified points.
    int lengthOfData, lengthOfPoints;

    Flower **flowers = getDataFromFile("classified.csv", &lengthOfData); //fill "flowers" with classifieds.
    Point **unclassifiedPoints = getPointsFromFile("unclassified.csv", &lengthOfPoints);

    KNNClassifier knnClassifier = KNNClassifier(flowers, lengthOfData); //new KNNClassifier.

//EuclideanDistance

    auto** classifiedPoints = classifyAll(new EuclideanDistance(),
                                          knnClassifier, unclassifiedPoints, lengthOfPoints, k);
    copyToFile("euclidean_output.csv", classifiedPoints, lengthOfPoints); //copy the flowers to the file.

//ManhattanDistance

    classifiedPoints = classifyAll(new ManhattanDistance(),
                                          knnClassifier, unclassifiedPoints, lengthOfPoints, k);
    copyToFile("manhattan_output.csv", classifiedPoints, lengthOfPoints); //copy the flowers to the file

//ChebyshevDistance

    classifiedPoints = classifyAll(new ChebyshevDistance(),
                                   knnClassifier, unclassifiedPoints, lengthOfPoints, k);
    copyToFile("chebyshev_output.csv", classifiedPoints, lengthOfPoints); //copy the flowers to the file.

}

