#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sender.h"
#include <string.h>

using namespace std;

//Positive Scenarios
TEST_CASE("Read Data from a File"){
  int totalReadingsCaptured = 0;
  float Temperature[50];
  float ChargeRate[50];
  char *filename = "./Sensor1_Data.txt";
  totalReadingsCaptured = m_readDataFromAFile(filename,&Temperature[0],&ChargeRate[0]);
  REQUIRE (totalReadingsCaptured == 50);
  }

/*TEST_CASE("Whether data read successfully"){
  int isReadingSuccess = 0;
  char *filename = "./Sensor1_Data.txt";
  isReadingSuccess = isDataReadSuccessfully(filename);
  REQUIRE (isReadingSuccess == 1);
  }*/

//Negative Scenarios
/*TEST_CASE("Read Data from a not present File"){
  int totalReadingsCaptured = 0;
  float Temperature;
  float ChargeRate;
  char *filename = "./SensorData.txt";
  totalReadingsCaptured = m_readDataFromAFile(filename,&Temperature,&ChargeRate);
  REQUIRE (totalReadingsCaptured == 0);
  }*/

/*TEST_CASE("When data is not available"){
  int isReadingSuccess = 0;
  char *filename = "./SensorData.txt";
  isReadingSuccess = isDataReadSuccessfully(filename);
  REQUIRE (isReadingSuccess == 0);
  }*/
