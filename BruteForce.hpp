#ifndef BRUTEFORCE_HPP
#define BRUTEFORCE_HPP
#include <vector>
#include "DistanceMatrix.hpp"

class BruteForce
{
public:
   BruteForce(int numCities);
   void traverse(int previous = 0);
   double sumTraversal();
   double sumBestPath();
   std::vector<double> GetBestPath();
private:
   DistanceMatrix DM;
   double bestPathSum = 9000000.0;
   double sumOfTraversal = 0.0;
   int numCities;
   std::vector<double> currentPath;
   std::vector<double> bestPath;
   std::vector<bool> visited;

};

#endif