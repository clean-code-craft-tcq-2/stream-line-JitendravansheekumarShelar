
#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "receiver.h"

TEST_CASE("Test for Receiever to read from console") 
{
  //float expectedTempValue[50] = {0};
  float temp[50], chargeRate[50], expectedTempValue[50], expectedChargeRate[50]  = {0};
//   float chargeRate[50] = {0};
//   float expectedTempValue[50] = {0};
//   float expectedChargeRate[50] = {0};
  float Temperature, chargeRateFromFile;
  receiveDataFromConsole(temp,chargeRate);  
  
  FILE * file= fopen("./batteryParameters.txt","r");                                                                  
   for(int i = 0 ; i < 50; i++)
   {
     if (file!=NULL) 
     {
        for(int i=0;fscanf(file, "%f\t%f\n", &Temperature,&chargeRateFromFile)!=EOF ;i++)
        {
            expectedTempValue[i] = Temperature;
            expectedChargeRate[i] = chargeRateFromFile;
        }
     }
       
     REQUIRE( (temp[i] - expectedTempValue[i]) <= 0.001);
     REQUIRE( (chargeRate[i] - expectedChargeRate[i]) <= 0.001);
   }
   fclose(file);
}
