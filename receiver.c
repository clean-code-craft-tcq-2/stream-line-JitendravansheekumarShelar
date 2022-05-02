
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "receiver.h"

#define BUFFER_SIZE 50

void printMinMaxValuesInStream(float* tempData, float* chargeRateData) {
    float minTemp=0, maxTemp=0, minChargeRate=0, maxChargeRate=0;
    for (int j = 0; j < BUFFER_SIZE; j++)
    {
        if(tempData[j] < minTemp) {
            minTemp = tempData[j];
        } else if(tempData[j]> maxTemp) {
            maxTemp = tempData[j];
        }

        if(chargeRateData[j] < minChargeRate) {
            minChargeRate = chargeRateData[j];
        } else if(chargeRateData[j] > maxChargeRate) {
            maxChargeRate = chargeRateData[j];
        }
    }
    printf("Minimum Temperature in the stream: %f Maximum Temperature in the stream: %f Minimum Charge Rate in the stream: %f Maximum Charge Rate in the stream: %f\n", minTemp, maxTemp, minChargeRate, maxChargeRate);
}

int movingAverage(float value) {
    static int sampleSize = 0;
    static float movingAverageArray[5] ={0};
    movingAverageArray[sampleSize % 5] = value/5.0;
    sampleSize++;
    if (sampleSize >= 5)
    {
        float averageTemperature = movingAverageArray[0] +movingAverageArray[1] + movingAverageArray[2]+ movingAverageArray[3]+ movingAverageArray[4];
        printf("Average Temperature: %f\n", averageTemperature);
        return 1;
        
    } else{
        return -1;
    }
    
}

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
        scanf("%50s", unusedData);
        scanf("%50s", unusedData);
        scanf("%50s", unusedData);
        scanf("%f", &chargeRateData[j]);
        movingAverage(tempData[j]);
    }
   
}

void receiver(float* tempData, float* chargeRateData)
{
    receiveDataFromConsole(tempData, chargeRateData);
    printMinMaxValuesInStream(tempData, chargeRateData);    
}
