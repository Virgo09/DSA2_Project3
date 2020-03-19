#include "BruteForce.hpp"

BruteForce::BruteForce(int numCities)
{
   this -> numCities = numCities;
   DM.readFile();
   for(int i = 1; i <= numCities; i++)
   {
      s.push_back(i);
   }
   
   int perms = 1;
   for(int i = numCities; i > 0; i--)
   {
      perms *= i;
   }
   traverse(perms);
}

void BruteForce::traverse(int permsThisCall)
{
   int m, k, p , q, i, j;

   for(j = 0; j < permsThisCall; j++)
   {
      for( i = 0; i < numCities - 1; i++)
      {
         currentPath.push_back(DM.GetElement(s[i]-1,s[i+1]-1));
         if(i == numCities - 2)
         {
            currentPath.push_back(DM.GetElement(s[i+1]-1,s[0]-1));
         }
      }

      sumOfTraversal = sumTraversal();
      if(sumOfTraversal < bestPathSum)
      {
         bestS.assign(s.begin(),s.end());
         bestPathSum = sumOfTraversal;
         bestPath.assign(currentPath.begin(),currentPath.end());
      }
   
      m = numCities - 2;
      while(s[m] > s[m + 1])
      {
         m = m - 1;
      }
      k = numCities - 1;
      while(s[m] > s[k])
      {
         k = k - 1;
      }
      swap(m,k);
      p = m + 1;
      q = numCities - 1;
      while( p < q)
      {
         swap(p,q);
         p++;
         q--;
      }
   
      while(currentPath.size())
      {
         currentPath.pop_back();
      }  
   }
}

void BruteForce::swap(int m, int k)
{
   int temp;
   temp = s[m];
   s[m] = s[k];
   s[k] = temp;
}

double BruteForce::sumTraversal()
{
   double sum = 0;
   for(int i = 0; i < numCities; i++)
   {
      if(currentPath[i] == 0.0)
      {
         return DBL_MAX;
      }
      sum += currentPath[i];
   }   
   return sum;
}
void BruteForce::printS()
{
   for(int i = 0; i < numCities; i++)
   {
      std::cout << s[i] << " -> ";
   }
   
   std::cout << s[0] << ":" << std::endl;
   
   for(int i = 0; i < numCities-1; i++)
   {
      std::cout << currentPath[i] << " -> ";
   }
   std::cout << currentPath[numCities - 1] << std::endl;
}

void BruteForce::printBestS()
{
   for(int i = 0; i < numCities; i++)
   { 
      std::cout << bestS[i] << " -> ";
   }
   std::cout << bestS[0] << ":" << std::endl;
   for(int i = 0; i < numCities-1; i++)
   {
      std::cout << bestPath[i] << " -> ";
   }
   std::cout << bestPath[numCities - 1] << std::endl;
}

std::vector<double> BruteForce::GetBestPath()
{
   return this -> bestPath;
}
