#define CATCH_CONFIG_MAIN

#include "catch/catch.hpp"
#include "../DistanceMatrix.cpp"


TEST_CASE("Testing the formation of the adjacency matrix")
{
   DistanceMatrix obj;
   
   obj.readFile();
   obj.displayMatrix();
}
// Compile & run:
// make clean test
