#include "BruteForce.hpp"

BruteForce::BruteForce(int numCities)
{
   this -> numCities = numCities;
   DM.readFile();
<<<<<<< HEAD
=======
   visited.resize(numCities, false);
   traverse();
}

void BruteForce::traverse(int previous)
{
   std::cout << previous << std::endl;
   //Check that we're not doing the same row again
   if(visited[previous])
   {
      return;
   }
   
   //Set the previous location as visited
   visited[previous] = true;
   
   //Check that we haven't reached all cities
   if(currentPath.size() == numCities + 1)
   {
      return;
   }
   
   for(int i = 0; i < numCities; i++)
   {
      std::cout << i << std::endl;
   
      if(previous != i && !visited[i])
      {
         currentPath.push_back(DM.GetElement(previous,i));
         traverse(i); 
      }
      if(currentPath.size() == numCities - 1 && i != 0)
      {
         currentPath.push_back(DM.GetElement(i,0));
         break;
      }
   }      
   //If there is a full path set and it is shorter than the last
   //full traversal, make it the best path and store it
   if(currentPath.size() == numCities)
   {
      sumOfTraversal = sumTraversal();
      if(sumOfTraversal < bestPathSum)
      {
         bestPathSum = sumOfTraversal;
         bestPath = currentPath;
      }
   }
   visited[previous] = false;
   currentPath.pop_back();
   return;

/*
   std::cout << "13" << std::endl;
   if(visited[previous])
   {
      return;
   }
   
   std::cout << "18" << std::endl;
>>>>>>> d4b22433f813883bf6a87d6003e06078883cf3dd
   
   for(int i = 1; i <= numCities; i++)
   {
      s.push_back(i);
   }
   s.push_back(0);
   
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
         bestS = s;
         bestPathSum = sumOfTraversal;
         bestPath = currentPath;
      }
   //printS();
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
<<<<<<< HEAD
   std::cout << bestPath[numCities - 1] << std::endl;
=======
   
   std::cout << "72" << std::endl;
   
   visited[previous] = false;
   currentPath.pop_back();
   */
>>>>>>> d4b22433f813883bf6a87d6003e06078883cf3dd
}

double BruteForce::sumTraversal()
{
   double sum = 0;
   for(int i = 0; i <= numCities; i++)
   {
      if(currentPath[i] == 0.0)
      {
         return DBL_MAX;
      }
      sum += currentPath[i];
   }
   return sum;
}

std::vector<double> BruteForce::GetBestPath()
{
   return this -> bestPath;
}

double BruteForce::GetBestSum()
{
   return this -> bestPathSum;
}