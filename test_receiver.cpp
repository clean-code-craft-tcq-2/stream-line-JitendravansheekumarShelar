
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

TEST_CASE("Test for Receiever to read from console and validate with File contents") 
{
  float temp[50], chargeRate[50], expectedTempValue[50], expectedChargeRate[50] = {0};
  float Temperature, chargeRateFromFile;
  receiveDataFromConsole(temp,chargeRate);                                                              

  FILE * file= fopen("./Sensor1_Data.txt","r");                                                                  
  if (file!=NULL) 
  {
     for(int i=0;fscanf(file, "%f\t%f\n", &Temperature,&chargeRateFromFile)!=EOF ;i++)
        {
            expectedTempValue[i] = Temperature;
            expectedChargeRate[i] = chargeRateFromFile;
            printf("The actual value for temp is %f and the expected value is %f", temp[i], expectedTempValue[i]);
            REQUIRE( (temp[i] - expectedTempValue[i]) <= 0.001);
            REQUIRE( (chargeRate[i] - expectedChargeRate[i]) <= 0.001);
        }
   }
   fclose(file);
}
