#ifndef BRUTEFORCE_HPP
#define BRUTEFORCE_HPP
#include <vector>
#include <float.h>
#include "DistanceMatrix.hpp"

class BruteForce
{
public:
   BruteForce(int numCities);
   void traverse(int permsThisCall = 1);
   void swap(int m, int k);
   void printS();
   void printBestS();
   double sumTraversal();
   double sumBestPath();
   double GetBestSum();
   std::vector<double> GetBestPath();
private:
   DistanceMatrix DM;
   double bestPathSum = DBL_MAX;
   double sumOfTraversal = 0.0;
   int numCities;
   std::vector<int> s;
   std::vector<int> bestS;
   std::vector<double> currentPath;
   std::vector<double> bestPath;
};

#endif