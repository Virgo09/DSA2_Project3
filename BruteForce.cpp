#include "BruteForce.hpp"

BruteForce::BruteForce(int numCities, std::vector<std::vector<double>> &matrix)
{
   this -> numCities = numCities;
   this -> matrix = matrix;
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

   start = std::chrono::steady_clock::now();
   
   for(j = 0; j < permsThisCall; j++)
   {
      for( i = 0; i < numCities - 1; i++)
      {
         currentPath.push_back(matrix[s[i]-1][s[i+1]-1]);
         if(i == numCities - 2)
         {
            currentPath.push_back(matrix[s[i+1]-1][s[0]-1]);
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
   end = std::chrono::steady_clock::now();

   time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
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

std::chrono::duration<double> BruteForce::GetTimeSpan()
{
   return this -> time_span;
}

double BruteForce::GetBestSum()
{
   return this -> bestPathSum;
}