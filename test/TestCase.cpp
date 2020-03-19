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
   BruteForce* obj = new BruteForce(12);
   
   obj -> printBestS();

}
// Compile & run:
// make clean test
