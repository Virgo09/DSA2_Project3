#define CATCH_CONFIG_MAIN

#include "catch/catch.hpp"
#include "../DistanceMatrix.cpp"
#include "../BruteForce.cpp"


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
   BruteForce* obj = new BruteForce(3);
   
   std::cout << obj -> GetBestPath()[0];   
   std::cout << obj -> GetBestPath()[1];
   std::cout << obj -> GetBestPath()[2];
}
// Compile & run:
// make clean test
