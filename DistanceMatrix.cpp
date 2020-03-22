#include "DistanceMatrix.hpp"

DistanceMatrix::DistanceMatrix()
{
   //matrix(NUM_ROWS, std::vector<double>(NUM_COLS, 0.0));
   matrix.resize(NUM_ROWS);
   for(int i = 0; i < NUM_COLS; i++)
   {
      matrix[i].resize(NUM_COLS);
   }
   

   readFile();
}

std::vector<std::vector<double>> DistanceMatrix::GetMatrix()
{
   return this -> matrix;
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
            matrix[i].push_back(0.0);
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

