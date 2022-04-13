
#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "receiver.h"

TEST_CASE("Test for Receiever to read from console") 
{
  float temp[6];
  float chargeRate[6;
  float expectedTempValue[6 = {35, 33, 49, 46, 30, 37};
  float expectedChargeRate[] = {55, 60, 58, 52, 59, 51};
  for(int i =0; i<6; i++){
    printf(" Temperature: %.2f, Charge Rate: %.2f \n", expectedTempValue[0], expectedChargeRate[0] );
  }
  receiveDataFromConsole(expectedTempValue,expectedChargeRate);  
}
