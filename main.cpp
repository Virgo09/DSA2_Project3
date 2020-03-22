#include "BruteForce.cpp"
#include "Genetic.cpp"
#include "DistanceMatrix.cpp"

int main()
{
   int numCities;
   int numTours;
   int numGens;
   int percentMutations;
   DistanceMatrix DM;
   
   std::vector<std::vector<double>> matrix = DM.GetMatrix();
   
   std::cout << "How many cities do you want to calculate? ";
   std::cin >> numCities;
   
   std::cout << "How many tours do you want to calculate? ";
   std::cin >> numTours;
   
   std::cout << "How many generations do you want to calculate? ";
   std::cin >> numGens;
   
   std::cout << "What percentage of mutations do you want to calculate? (0 - 100 exclusive) ";
   std::cin >> percentMutations;
   
   BruteForce* BF = new BruteForce(numCities, matrix);
   Genetic* GM = new Genetic(numCities, numTours, numGens, percentMutations, matrix);
   DM.displayMatrix();
   std::cout << "The best order of cities to travel in is:\n";
   BF -> printBestS();
   std::cout << "The result from the genetic algorith is:\n";
   GM -> PrintElite();
   std::cout << "It took " << BF -> GetTimeSpan().count() << " seconds to complete the Brute Force\n";

   std::cout << "It took " << GM -> GetTimeSpan().count() << " seconds to complete the Genetic\n";
   std::cout << "And the percent of optimal is " << GM -> GetEliteSum() / BF -> GetBestSum() * 100 << "% of optimal\n";
   return 0;
}