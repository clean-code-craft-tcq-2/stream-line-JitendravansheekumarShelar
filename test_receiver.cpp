
#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "receiver.h"
#include <stdio.h>

TEST_CASE("Test for Receiever to read from console") 
{
  float temp[50], chargeRate[50]  = {0};
  receiveDataFromConsole(temp,chargeRate);                                                              
  float expectedTempValue[50] = {35, 33, 49, 46};
  float expectedChargeRate[50] = {55, 60, 58, 52};
  for(int i =0; i< 4; i++){
  REQUIRE( (temp[i] - expectedTempValue[i]) <= 0.001);
  REQUIRE( (chargeRate[i] - expectedChargeRate[i]) <= 0.001);
  }
}

TEST_CASE("Test for Min and max values of battery parameters in the stream") 
{
  float temp[50], chargeRate[50]  = {0};
  receiveDataFromConsole(temp,chargeRate);                                                              
  printMinMaxValuesInStream(temp,chargeRate);
}
