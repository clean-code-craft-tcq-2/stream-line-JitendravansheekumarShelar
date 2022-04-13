
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "receiver.h"

#define BUFFER_SIZE 6

// Here we consider that the output printed on console (By sender) is of the type
// Temperature: 31.342, Charge Rate: 0.413
void receiveDataFromConsole(float* tempData, float* chargeRateData) {
    char unusedData[300];
    for(int j = 0; j < BUFFER_SIZE; j++){
        if(scanf("%50s", unusedData) == EOF) 
        {
            break;
        } 
        scanf("%f", &tempData[j]);
        printf("%f\n", tempData[j]);        
        scanf("%50s", unusedData);
        scanf("%50s", unusedData);
        scanf("%50s", unusedData);
        scanf("%f", &chargeRateData[j]);
        printf("%f\n", chargeRateData[j]);        
    }
    printf("Data received from console\n");
    for(int i = 0; i<6; i++){
    printf("Temperature: %.2f, Charge Rate: %.2f \n", tempData[i], chargeRateData[i]);
  }
}
