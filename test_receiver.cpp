
#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "receiver.h"

TEST_CASE("Test for Receiever to read from console") 
{
  float temp[6] = {0};
  float chargeRate[6] = {0};
  float expectedTempValue[6] = {35, 33, 49, 46, 30, 37};
  float expectedChargeRate[6] = {55, 60, 58, 52, 59, 51};
  //printf("Print the data on console\n");
  for(int i = 0; i<6; i++){
    printf("Temperature: %.2f, Charge Rate: %.2f \n", expectedTempValue[i], expectedChargeRate[i]);
  }
  receiveDataFromConsole(temp,chargeRate);  
  printf("Print the received data from console\n");
  for(int i = 0; i<6; i++){
    printf("Temperature: %.2f, Charge Rate: %.2f \n", temp[i], chargeRate[i]);
  }
  
}
