#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sender.h"

using namespace std;


TEST_CASE("Read Data from a File"){
  int totalReadingsCaptured = 0;
  totalReadingsCaptured = m_readDataFromAFile();
  REQUIRE (totalReadingsCaptured == 50);
  }
