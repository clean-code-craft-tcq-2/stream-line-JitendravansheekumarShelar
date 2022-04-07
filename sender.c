#include <string.h>
#include "sender.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 50

// Declare data buffer
float dataBuffer[BUFFER_SIZE] = {0};

int isFileOpenSuccessfully(char *filename)
{
    // Declare the file pointer
    FILE *filePointer ;
    
    // Open the existing file Sensor1_Data.csv using fopen()
    // in read mode using "r" attribute
    filePointer = fopen(filename, "r") ;
    
    // Check if this filePointer is null
    // which maybe if the file does not exist
    if ( filePointer == NULL )
    {
        return 0;
    }
    else
    {       
        return 1;
    }
}

int readData(char * filename, float *Temperature, float *ChargeRate)
{
    float Temp_data = 0, ChargeRate_data = 0;
    int index_pos;
    
    // Declare the file pointer
    FILE *filePointer ;
    
    // Open the existing file Sensor1_Data.csv using fopen()
    // in read mode using "r" attribute
    filePointer = fopen(filename, "r") ;
  
    for(index_pos=0; index_pos<BUFFER_SIZE; index_pos++)
    {
      fscanf(filePointer, "%f , %f \n", &Temp_data,&ChargeRate_data);
      *(Temperature + index_pos) = Temp_data;
      *(ChargeRate + index_pos) = ChargeRate_data;
        printf("%f --- %f\n",Temp_data,ChargeRate_data);
    }
    
    fclose(filePointer);
    
    return index_pos;
}

int m_readDataFromAFile(char * filename, float *Temperature, float *ChargeRate)
{   
    if(isFileOpenSuccessfully(filename))
    {
        return readData(filename,Temperature,ChargeRate);
    }
    else
    {
        return 0;
    }
}
