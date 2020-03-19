#define CATCH_CONFIG_MAIN

#include "catch/catch.hpp"
#include "../DistanceMatrix.hpp"
#include "../BruteForce.hpp"


TEST_CASE("Testing the formation of the adjacency matrix")
{
   DistanceMatrix obj;
   
   obj.readFile();
   obj.displayMatrix();
   REQUIRE(obj.GetElement(0,1) == 25.41);
   REQUIRE(obj.GetElement(1,0) == 79.36);
}

TEST_CASE("Confirming the Brute Force class works properly")
{
<<<<<<< HEAD
   BruteForce* obj = new BruteForce(8);
  
   obj -> printBestS();
=======
   BruteForce* obj = new BruteForce(20);
   
   std::cout << obj -> GetBestPath()[0] << std::endl;
   std::cout << obj -> GetBestPath()[1] << std::endl;
   std::cout << obj -> GetBestPath()[2] << std::endl;
   std::cout << obj -> GetBestPath()[3] << std::endl;
   //std::cout << obj -> GetBestPath()[4] << std::endl;
   //std::cout << obj -> GetBestPath()[5] << std::endl;
   //std::cout << obj -> GetBestPath()[6] << std::endl;
   //std::cout << obj -> GetBestPath()[7] << std::endl;
   //std::cout << obj -> GetBestPath()[8] << std::endl;
   //std::cout << obj -> GetBestPath()[9] << std::endl;
   //std::cout << obj -> GetBestPath()[10] << std::endl;
   //std::cout << obj -> GetBestPath()[11] << std::endl;
   //std::cout << obj -> GetBestPath()[12] << std::endl;
   //std::cout << obj -> GetBestPath()[13] << std::endl;
   //std::cout << obj -> GetBestPath()[2] << std::endl;
>>>>>>> d4b22433f813883bf6a87d6003e06078883cf3dd
}
// Compile & run:
// make clean test
