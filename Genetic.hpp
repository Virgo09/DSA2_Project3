#ifndef GENETIC_HPP
#define GENETIC_HPP
#include <vector>
#include <float.h>
#include <ctime>
#include <ratio>
#include <chrono>
#include <iostream>

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