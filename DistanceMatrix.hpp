#ifndef DISTANCEMATRIX_HPP
#define DISTANCEMATRIX_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

class DistanceMatrix{
public:
   DistanceMatrix();
   std::vector<std::vector<double>> GetMatrix();
   void readFile();
   void insertDistance(int distance);
   void displayMatrix();
   
private:
   static const int NUM_ROWS = 20;
   static const int NUM_COLS = 20;
   std::vector<std::vector<double>> matrix;
   std::ifstream distanceFile;
};

#endif
