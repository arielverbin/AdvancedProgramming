cmake_minimum_required(VERSION 3.20)
project(AdvancedProgramming)

set(CMAKE_CXX_STANDARD 14)

add_executable(AdvancedProgramming
        main.cpp Point.cpp Point.hpp DistanceCalcs/DistanceCalculator.hpp DistanceCalcs/EuclideanDistance.cpp DistanceCalcs/EuclideanDistance.hpp DistanceCalcs/ManhattanDistance.cpp DistanceCalcs/ManhattanDistance.hpp DistanceCalcs/ChebyshevDistance.cpp DistanceCalcs/ChebyshevDistance.hpp Flowers/Flower.cpp Flowers/Flower.hpp KNNClassifier.cpp KNNClassifier.hpp)
