cmake_minimum_required(VERSION 3.20)
project(AdvancedProgramming)

set(CMAKE_CXX_STANDARD 14)

add_executable(AdvancedProgramming
        main.cpp Point.cpp Point.h DistanceCalcs/DistanceCalculator.h DistanceCalcs/EuclideanDistance.cpp DistanceCalcs/EuclideanDistance.h DistanceCalcs/ManhattanDistance.cpp DistanceCalcs/ManhattanDistance.h DistanceCalcs/ChebyshevDistance.cpp DistanceCalcs/ChebyshevDistance.h Flowers/Flower.cpp Flowers/Flower.h KNNclassifier.cpp KNNclassifier.h)
