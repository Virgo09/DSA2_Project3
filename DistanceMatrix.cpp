#include "DistanceMatrix.hpp"

DistanceMatrix::DistanceMatrix()
{}

double DistanceMatrix::GetElement(int row, int col)
{
   return this -> matrix[row][col];
}

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
   for(int i = 0; i < NUM_ROWS; i++)
   {
      for(int j = 0; j < NUM_COLS; j++)
      {
         std::cout << std::setw(6) << matrix[i][j] << " ";
      }
      std::cout << std::endl;
   }
}