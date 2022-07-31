#include <iostream>
#include "Point.hpp"
#include "Flowers/Flower.hpp"
#include "KNNClassifier.hpp"
#include "DistanceCalcs/ManhattanDistance.hpp"
#include "DistanceCalcs/EuclideanDistance.hpp"
#include "DistanceCalcs/ChebyshevDistance.hpp"
#include <fstream>
#include<vector>

using namespace std;

/**
 * @brief Get the Data From File object - Creates a new vector with 
 * the flowers from the given file.
 * @param fileName the given file.
 * @return vector<Flower> 
 */
vector<Flower> getDataFromFile(const std::string &fileName) {
    vector<Flower> l;
    string line;
    ifstream input;
    input.open(fileName);
    if (input.fail()) {
        cout << "Could not open " << fileName << endl;
        input.close();
        throw std::exception();
    }
    while (!input.eof()) {
        getline(input, line);
        if (std::equal(line.begin(), line.end(), "")) continue; // avoid an empty line.
        l.emplace_back(Flower(line));
    }
    input.close();
    return l;
}

/**
 * Creates a new vector with the points (unclassified flowers) from the given file.
 * @param fileName the given file.
 * @return the vector.
 */
vector<Point> getPointsFromFile(const std::string &fileName) {
    vector<Point> l;
    string line;
    ifstream input;
    input.open(fileName);
    if (input.fail()) {
        cout << "Could not open " << fileName << endl;
        input.close();
        throw std::exception();
    }
    while (!input.eof()) {
        getline(input, line);
        if (std::equal(line.begin(), line.end(), "")) continue; // avoid an empty line.
        l.emplace_back(Point(line));
    }
    input.close();
    return l;
}

/**
 * Copy the classified points to a given file.
 * @param fileName the file.
 * @param flowers the classified points (as flowers)
 */
void copyToFile(const std::string &fileName, vector<Flower> flowers) {
    ofstream output;
    output.open(fileName);
    for (auto &flower: flowers) {
        output << flower.getType() << endl;
    }
    output.close();
}

/**
 * classify all of the points according to the given classifier, distance calculator, and k.
 * @param dc the distance calculator.
 * @param knn the classifier.
 * @param unclassifiedPoints the points to be classified.
 * @param k the constant k from the algorithm.
 * @return new vector of classified points (as flowers).
 */
vector<Flower> classifyAll(DistanceCalculator &dc, KNNClassifier &knn,
                           vector<Point> &unclassifiedPoints, int k) {
    vector<Flower> classifiedPoints; //to be filled with the classified points.

    for (auto &curPoint: unclassifiedPoints) {
        //take the current point.
        classifiedPoints.emplace_back(Flower(curPoint, //classify it and create a new flower.
                                      knn.classify(curPoint, k, dc)));
    }
    return classifiedPoints;
}

/**
 * main.
 */
int main(int argc, char** argv) {
    int k = stoi(argv[1]);

    vector<Flower> flowers = getDataFromFile("Input/classified.csv"); //fill "flowers" with classifieds.
    vector<Point> unclassifiedPoints = getPointsFromFile("Input/unclassified.csv");

    KNNClassifier knnClassifier = KNNClassifier(flowers); //new KNNClassifier.
    auto *euclideanDistance = new EuclideanDistance();
    auto *chebyshevDistance = new ChebyshevDistance();
    auto *manhattanDistance = new ManhattanDistance();

//EuclideanDistance

    vector<Flower> classifiedPoints = classifyAll(*euclideanDistance,
                                                  knnClassifier, unclassifiedPoints, k);

    copyToFile("Output/euclidean_output.csv", classifiedPoints); //copy the flowers to the file.

//ManhattanDistance

    classifiedPoints = classifyAll(*manhattanDistance,
                                   knnClassifier, unclassifiedPoints, k);
    copyToFile("Output/manhattan_output.csv", classifiedPoints); //copy the flowers to the file

//ChebyshevDistance

    classifiedPoints = classifyAll(*chebyshevDistance,
                                   knnClassifier, unclassifiedPoints, k);
    copyToFile("Output/chebyshev_output.csv", classifiedPoints); //copy the flowers to the file.

    delete euclideanDistance;
    delete manhattanDistance;
    delete chebyshevDistance;
}