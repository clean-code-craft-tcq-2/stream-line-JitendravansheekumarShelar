
#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "receiver.h"

TEST_CASE("Test for Receiever to read from console") 
{
  float temp[50], chargeRate[50], expectedTempValue[50], expectedChargeRate[50]  = {0};
  float Temperature, chargeRateFromFile;
  receiveDataFromConsole(temp,chargeRate);  
  FILE * file= fopen("./Sensor1_Data.txt","r");                                                                  
   for(int i = 0 ; i < 5; i++)
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
