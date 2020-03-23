#ifndef GENETIC_HPP
#define GENETIC_HPP
#include <vector>
#include <float.h>
#include <ctime>
#include <ratio>
#include <chrono>
#include <iostream>
/***************************************************************
  Student Name: Justin Wymore
  File Name: Genetic
  Assignment number 3

  This class will take a passed in matrix and logically try a
  numerous combination of nodes to find the shortest route possible
  starting at most note and ending at the same node
  The margin of error will increase as the number of cities increases
  unless the other 3 parameters are sufficiantly increased as well
***************************************************************/
class Genetic
{
public:
   Genetic(int numCities, int numTours, int numGens, int percentMutations, std::vector<std::vector<double>> &matrix);
   void generateMutations();
   void swap(int m, int k);
   void rankAndFile();
   void quickSort(int left, int right);
   double sumPath(std::vector<int> path);
   std::chrono::duration<double> GetTimeSpan();
   void PrintElite();
   double GetEliteSum();
      
private:
   int numCities;        // number of cities to test
   int numTours;         // number of paths in a generation
   int numGens;          // number of generations to run
   int percentMutations; // amount of mutations that occupy generation
   std::vector<std::vector<double>> matrix;
   std::vector<int> currentPath;
   std::vector<double> path;
   std::vector<std::vector<int>> elite;
   std::vector<std::vector<int>> permutations;
   std::vector<std::vector<int>> mutations;
   std::chrono::steady_clock::time_point start;
   std::chrono::steady_clock::time_point end;
   std::chrono::duration<double> time_span;
};

#endif