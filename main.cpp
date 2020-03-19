#include "BruteForce.hpp"

int main()
{
   int numCities;

   std::cout << "How many cities do you want to calculate? ";
   std::cin >> numCities;

   BruteForce* BF = new BruteForce(numCities);

   std::cout << "The best order of cities to travel in is:\n";

   BF -> printBestS();

}