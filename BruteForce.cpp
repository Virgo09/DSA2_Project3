#include "BruteForce.hpp"

BruteForce::BruteForce(int numCities)
{
   this -> numCities = numCities;
   DM.readFile();
   visited.resize(numCities, false);
   traverse();
}

void BruteForce::traverse(int previous)
{
   std::cout << "13" << std::endl;
   if(visited[previous])
   {
      return;
   }
   
   std::cout << "18" << std::endl;
   
   if(currentPath.size() == numCities)
   {
      return;
   }
   
   std::cout << "23" << std::endl;
   
   int next;
   int row = previous / numCities;
   int col = previous % numCities;
   
   std::cout << DM.GetElement(row,col) << std::endl;
   
   if(row != col)
   {
      currentPath.push_back(DM.GetElement(row,col)); 
   }
   
   std::cout << "32" << std::endl;
   
   visited[previous] = true;
   
   next = previous;
   next += 1;
   if(next % numCities == 0)
   {
      next -= numCities;
   }
   traverse(next);
   
   std::cout << "42" << std::endl;
   
   next = previous;
   next += numCities;
   if(next >= numCities * numCities - 1)
   {
      next -= numCities * numCities;
   }
   traverse(next);
   
   std::cout << "50" << std::endl;
   
   next = previous;
   next -= 1;
   if(next % numCities == numCities - 1 || next == -1)
   {
      next += numCities;
   }
   traverse(next);
   
   std::cout << "58" << std::endl;
   
   next = previous;
   next -= numCities;
   if(next < 0)
   {
      next += numCities * numCities;
   }
   traverse(next);
   
   std::cout << "66" << std::endl;
   
   if(sumTraversal() < bestPathSum)
   {
      bestPathSum = sumOfTraversal;
      bestPath = currentPath;
   }
   
   std::cout << "72" << std::endl;
   
   visited[previous] = false;
   currentPath.pop_back();
}

double BruteForce::sumTraversal()
{
   double sum = 0;
   for(int i = 0; i < numCities; i++)
   {
      if(currentPath[i] == 0.0)
      {
         return 99999.9;
      }
      sum += currentPath[i];
   }
   return sum;
}

std::vector<double> BruteForce::GetBestPath()
{
   return this -> bestPath;
}