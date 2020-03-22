#ifndef BRUTEFORCE_HPP
#define BRUTEFORCE_HPP
#include <vector>
#include <float.h>
#include <ctime>
#include <ratio>
#include <chrono>
#include <iostream>

class BruteForce
{
public:
   BruteForce(int numCities, std::vector<std::vector<double>> &matrix);
   void traverse(int permsThisCall = 1);
   void swap(int m, int k);
   void printS();
   void printBestS();
   double GetBestSum();
   double sumTraversal();
   double sumBestPath();
   std::vector<double> GetBestPath();
   std::chrono::duration<double> GetTimeSpan();
private:
   double bestPathSum = DBL_MAX;
   double sumOfTraversal = 0.0;
   int numCities;
   std::vector<int> s;
   std::vector<int> bestS;
   std::vector<double> currentPath;
   std::vector<double> bestPath;
   std::vector<std::vector<double>> matrix;
   std::chrono::steady_clock::time_point start;
   std::chrono::steady_clock::time_point end;
   std::chrono::duration<double> time_span;
};

#endif
