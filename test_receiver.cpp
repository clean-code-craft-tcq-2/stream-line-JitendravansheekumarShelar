
#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "receiver.h"
#include <stdio.h>

TEST_CASE("Test for Receiever to read from console") 
{
  float temp[50], chargeRate[50]  = {0};
  float Temperature, chargeRateFromFile;
  receiveDataFromConsole(temp,chargeRate);                                                              
  float expectedTempValue[50] = {35, 33, 49, 46};
  float expectedChargeRate[50] = {55, 60, 58, 52};
       
  REQUIRE( (temp[i] - expectedTempValue[i]) <= 0.001);
  REQUIRE( (chargeRate[i] - expectedChargeRate[i]) <= 0.001);

}
