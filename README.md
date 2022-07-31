# AdvancedProgramming

#**An explanation about our program:**

First, we defined a class called *Point* that stores a vector of 'double' values.
Then we defined a *Flower*, which stores a 'Point' and a String. The point represents the flower's measurements, and the string represents the flower's type.

At the same time, we wrote three classes - one for each distance formula.
We used the abstract class called *DistanceCalculator* to avoid code duplications.
We also implemented the *KNNClassifier* class with a single method - 'classify.' Its purpose is to perform the KNN algorithm.
The role of the main class is to open the input files, calculate and save the algorithm's results on the output files.

The input files are located in the folder **src/Input,** and the output files are created (or overwritten) in the folder **src/Output.**

#**Instructions to run:**
1. Run the command `g++ *.cpp DistanceCalcs/*.cpp Flowers/*.cpp -std=c++11`, inside the **src** folder, using Terminal.
2. A file named *a.out* should appear. Run the command `./a.out k` to run the program, and replace `k` with some Integer (for exmaple: `./a.out 5`).
3. The three output files should appear inside **src/Output** folder.
