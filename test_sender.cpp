#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sender.h"
#include <string.h>

using namespace std;

//Positive Scenarios
TEST_CASE("Read Sensor 1 Data"){
  int totalReadingsCaptured = 0;
  float Temperature[50]={0};
  float ChargeRate[50]={0};
  char *filename = "./Sensor1_Data.txt";
  totalReadingsCaptured = accessFileForDataExtraction(filename,&Temperature[0],&ChargeRate[0]);
  REQUIRE (totalReadingsCaptured == 50);
  }

// TEST_CASE("Read Sensor 2 Data"){
//   int totalReadingsCaptured = 0;
//   float Temperature[50]={0};
//   float ChargeRate[50]={0};
//   char *filename = "./Sensor2_Data.txt";
//   totalReadingsCaptured = accessFileForDataExtraction(filename,&Temperature[0],&ChargeRate[0]);
//   REQUIRE (totalReadingsCaptured == 50);
//   }

//Negative Scenarios
TEST_CASE("Read Data from a not present File"){
  int totalReadingsCaptured = 0;
  float Temperature[50]={0};
  float ChargeRate[50]={0};
  char *filename = "./SensorData.txt";
  totalReadingsCaptured = accessFileForDataExtraction(filename,&Temperature[0],&ChargeRate[0]);
  REQUIRE (totalReadingsCaptured == 0);
  }

