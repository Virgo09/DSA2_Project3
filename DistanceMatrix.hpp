#ifndef DISTANCEMATRIX_HPP
#define DISTANCEMATRIX_HPP

#include <fstream>
#include <iostream>
#include <string>


class DistanceMatrix{
public:
   DistanceMatrix();
   void readFile();
   void insertDistance(int distance);
   void displayMatrix();

private:
   static const int NUM_ROWS = 20;
   static const int NUM_COLS = 20;
   double matrix[NUM_ROWS][NUM_COLS];
   std::ifstream distanceFile;
};

#endif