#include "DistanceMatrix.hpp"

DistanceMatrix::DistanceMatrix()
{}

void DistanceMatrix::readFile()
{
   std::string num;

   distanceFile.open("distances.txt", std::ios::in);
   
   if(!distanceFile.is_open())
   {
      std::cout << "There was a problem opening the file!" << std::endl;
   }
   
   for(int i = 0; i < NUM_ROWS; i++)
   {
      for(int j = 0; j < NUM_COLS; j++)
      {
         if(i == j)
         {
            matrix[i][j] = 0.0;
         }
         else
         {
            distanceFile >> matrix[i][j];
         }
      }
   }   
}
         
void DistanceMatrix::displayMatrix()
{
   for(int i = 0; i < 20; i++)
   {
      for(int j = 0; j < 20; j++)
      {
         std::cout << std::setw(6) << matrix[i][j] << " ";
      }
      std::cout << std::endl;
   }
}