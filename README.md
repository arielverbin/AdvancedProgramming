# K Nearest Neighbors

## The Algorithm

We would like to classify an object to a certain membership (in our case - an Iris type) based on the most common class among its *k* nearest neighbors. If k=1, for example, the object is simply assigned to the class of its nearest neighbor.

We are given three classes via an Input file - *classified.csv*. The three classes are three types of iris flowers, and each flower is described as four measurements. Using this data, we will classify any measurement from the *unclassified.csv* file into the most common Iris-type among its *k* closest neighbors. In this way, we can estimate the type to which the measurement belongs.

## Our Implementation

First, we created a class named *Point*, its purpose is to store the four measurements of each Iris.
Then we defined a *Flower*, which holds a 'Point' and a String. The point represents the flower's measurements, and the string represents the flower's type.

In order to determine which measurement is closer to which, we implemented three *Distance Calculators* that tell us the distance between two points. Each distance calculator uses a different formula - *Euclidean Distance*, *Manhattan Distance*, and *Chebyshev Distance*.
We used the abstract class called *DistanceCalculator* to avoid code duplications.

We also implemented the *KNNClassifier* class with a single method - 'classify.' Its purpose is to perform the KNN algorithm.
The method gets an unclassified measurement, and sorts the classified irises from the closest one to the furthest, according to their measurements and the given distance calculator. Then, the method looks for the most common type among the first *k* irises. It creates a new Flower with the iris type found, and returns it.

The role of the main class is to open the input files and calculate and save the algorithm's results on the output files.

The input files are located in the folder **src/Input,** and the output files are created (or overwritten) in the folder **src/Output.**

## Instructions to run
1. Download the project and save it on your local device.
2. Open Terminal, and navigate to the project using `cd path/to/your/program` command. Then, enter into the **src** folder, inside the project (using `cd src`).
4. Run the command `g++ *.cpp DistanceCalcs/*.cpp Flowers/*.cpp -std=c++11` on your Terminal.
5. A file named *a.out* should appear. Run the command `./a.out k` to run the program, and replace `k` with some Integer (for example: `./a.out 5`).
6. The three output files should appear inside **src/Output** folder.
