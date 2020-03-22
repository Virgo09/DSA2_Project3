#include "Genetic.hpp"

Genetic::Genetic(int numCities, int numTours, int numGens, int percentMutations, std::vector<std::vector<double>> &matrix)
{
   this -> numCities = numCities;
   this -> numTours = numTours;
   this -> numGens = numGens;
   this -> percentMutations = percentMutations;
   this -> matrix = matrix;
   
   for(int i = 1; i <= numCities; i++)
   {
      currentPath.push_back(i);
   }
   
   start = std::chrono::steady_clock::now();
   
   for(int i = numGens; i > 0; i--)
   {
      generateMutations();
   }
   elite.push_back(permutations[0]);
   //elite[1] = permutations[1];
   end = std::chrono::steady_clock::now();

   time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
}

void Genetic::generateMutations()
{
   int m, k, p , q, i, j;

   
   if(mutations.size() == 0)
   {
      for(i = 0; i < numTours; i++)
      {
         permutations.push_back(currentPath);
         
         m = numCities - 2;
         while(currentPath[m] > currentPath[m + 1])
         {
            m = m - 1;
         }
         k = numCities - 1;
         while(currentPath[m] > currentPath[k])
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
      } 
      permutations.push_back(currentPath);     
   }
   
   else
   {
      int toMutate = numTours - permutations.size();
      for(j = 0; 0 < toMutate ; j++)
      {
         currentPath = permutations[j];
         m = numCities - 2;
         while(currentPath[m] > currentPath[m + 1])
         {
            m = m - 1;
         }
         k = numCities - 1;
         while(currentPath[m] > currentPath[k])
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
      
         permutations.push_back(currentPath);  
      }
   }
   quickSort(0,permutations.size() - 1);
   while(permutations.size() > (percentMutations * numTours) / 100)
   {
      permutations.pop_back();
   }
}
   
void Genetic::swap(int m, int k)
{
   int temp;
   temp = currentPath[m];
   currentPath[m] = currentPath[k];
   currentPath[k] = temp;

}
   
void Genetic::quickSort(int left, int right)
{
   if (left >= right)
   {
      return;
   }
   double pivot = sumPath(permutations[right]);

   int count = left;
   for (int i = left; i <= right; i++)
   {
      if (sumPath(permutations[i]) <= pivot)
      {
         std::vector<int> temp = permutations[count];
         permutations[count] = permutations[i];
         permutations[i] = temp;
         count++;
      }
   }
   quickSort(left, count-2); // Recursively sort the left side of pivot
   quickSort(count, right);   // Recursively sort the right side of pivot
}
   
double Genetic::sumPath(std::vector<int> path)
{
   double sum = 0.0;
   int i;
   for(i = 0; i < numCities - 1; i++)
   {
      sum += matrix[path[i] - 1][path[i + 1] - 1];
   }
   sum += matrix[path[i - 1] - 1][path[0] - 1];
   return sum;
}

std::chrono::duration<double> Genetic::GetTimeSpan()
{
   return this -> time_span;
}

void Genetic::PrintElite()
{
   int i = 0, j = 0;
   for(i = 0; i < numCities; i++)
   {
      std::cout << elite[0][i] << " -> ";
   }
   std::cout << elite[0][0] << std::endl;
   
   for(j = 0; j < numCities - 1; j++)
   {
      std::cout << matrix[elite[0][j] - 1][elite[0][j + 1] - 1] << " -> ";
   }
   std::cout << matrix[elite[0][j] - 1][elite[0][0]] << std::endl;
}

double Genetic::GetEliteSum()
{
   return sumPath(elite[0]);
}