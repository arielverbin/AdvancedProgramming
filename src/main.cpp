#include <iostream>
#include "Point.h"
#include "Flowers/Flower.h"
#include "KNNClassifier.h"
#include "DistanceCalcs/ManhattanDistance.h"
#include "DistanceCalcs/EuclideanDistance.h"
#include "DistanceCalcs/ChebyshevDistance.h"
#include <string>
#include <fstream>

using namespace std;
/**
 * @param fileName file name.
 * @param length pointer to am int.
 * @return a pointer to an array of flowers according to the given data in the file. It also returns the length
 *          of the array via "length" pointer.
 */
Flower **getDataFromFile(const std::string &fileName, int *length) {
    stack<Flower*> stack;
    ifstream input;
    input.open(fileName);
    if (input.fail()) {
        cout << "Could not open " << fileName << endl;
        exit(1);
    }
    string line;
    while (!input.eof()) {
        getline(input, line);
        if(std::equal(line.begin(), line.end(), "")) continue; // avoid an empty line.
        stack.push(new Flower(line, 4));
    }
    input.close();
    auto** flowers = new Flower *[stack.size()];
    *length = (int)stack.size();
    for(int i = *length - 1; i >= 0; i --) {
        flowers[i] = stack.top();
        stack.pop();
    }
    return flowers;
}
/**
 * @param fileName file name.
 * @param length pointer to am int.
 * @return a pointer to an array of points according to the given data in the file. It also returns the length
 *          of the array via "length" pointer.
 */
Point** getPointsFromFile(const std::string fileName, int *length){
    stack<Point*> stack;
    ifstream input;
    input.open(fileName);
    if (input.fail()) {
        cout << "Could not open " << fileName << endl;
        exit(1);
    }
    string line;
    while (!input.eof()) {
        getline(input, line);
        if(std::equal(line.begin(), line.end(), "")) continue; // avoid an empty line.
        stack.push(new Point(line,4));
    }
    input.close();
    auto** points = new Point *[stack.size()];
    *length = (int)stack.size();
    for(int i = *length - 1; i >= 0; i --) {
        points[i] = stack.top();
        stack.pop();
    }
    return points;
}
/**
 * Copy the classified points to a given file.
 * @param fileName the file.
 * @param flowers the classified points (as flowers)
 * @param length the length of the flowers array.
 */
void copyToFile(const std::string fileName, Flower** flowers, int length) {
    ofstream output;
    output.open (fileName);
    for(int i = 0; i < length; i ++) {
        output << flowers[i]->getType() << endl;
    }
    output.close();
}

/**
 * tests.
 * @return 0;
 */
int main() {
    int k = 11;
    int lengthOfData, lengthOfPoints; //length of classified flowers, length of unclassified points.
    Flower **flowers = getDataFromFile("classified.csv", &lengthOfData); //fill "flowers" with classifieds.
    KNNClassifier knnClassifier = KNNClassifier(flowers, lengthOfData); //new KNNClassifier.
    Point **unclassifiedPoints = getPointsFromFile("unclassified.csv", &lengthOfPoints);

    auto** classifiedPoints = new Flower*[lengthOfPoints]; //to be filled with the classified points.

    for(int i = 0; i < lengthOfPoints; i ++) {
        Point curPoint = *unclassifiedPoints[i]; //take the current point.
        classifiedPoints[i] = new Flower(curPoint, //classify it and create a new flower.
                                         knnClassifier.classify(curPoint,k, *new ChebyshevDistance()));
    }
    copyToFile("euclidean_output.csv", classifiedPoints, lengthOfPoints); //copy the flowers to the file.
}

