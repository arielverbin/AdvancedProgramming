#include <iostream>
#include "Point.h"
#include "Flowers/Flower.h"
#include <string>
#include <fstream>

using namespace std;

Flower **getDataFromFile(const std::string &fileName, int *length) {
    stack<Flower> stack;
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
        stack.push(Flower(line, 4));
    }
    input.close();
    auto** flowers = new Flower *[stack.size()];
    int i = (int)stack.size() - 1;
    *length = (int)stack.size();
    while(!stack.empty()) {
        flowers[i] = &stack.top();
        i--;
        stack.pop();
    }
    return flowers;
}

/**
 * tests.
 * @return 0;
 */
int main() {
    int length;
    Flower **flowers = getDataFromFile("classified.csv", &length);


}

