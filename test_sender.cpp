#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sender.h"

using namespace std;

//Positive Scenarios
TEST_CASE("Read Data from a File"){
  int totalReadingsCaptured = 0;
  char *filename = 'Sensor1_Data.csv'
  totalReadingsCaptured = m_readDataFromAFile(filename);
  REQUIRE (totalReadingsCaptured == 50);
  }

TEST_CASE("Whether data read successfully"){
  int isReadingSuccess = 0;
  char *filename = 'Sensor1_Data.csv
  isReadingSuccess = isDataReadSuccessfully(filename);
  REQUIRE (isReadingSuccess == 1);
  }

//Negative Scenarios
TEST_CASE("Read Data from a not present File"){
  int totalReadingsCaptured = 0;
  char *filename = 'SensorData.csv'
  totalReadingsCaptured = m_readDataFromAFile(filename);
  REQUIRE (totalReadingsCaptured == 0);
  }

TEST_CASE("When data is not available"){
  int isReadingSuccess = 0;
  char *filename = 'SensorData.csv'
  isReadingSuccess = isDataReadSuccessfully(filename);
  REQUIRE (isReadingSuccess == 0);
  }
