#include <string.h>
#include "sender.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 50

// Declare data buffer
float dataBuffer[BUFFER_SIZE] = {0};

FILE* fp = fopen("./BMS_DataParameter.txt","r");


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

int isDataReadSuccessfully(char *filename)
{
    if(m_readDataFromAFile(filename))
        return 1;
    else
        return 0;
}

int readData(char * filename)
{
    // Declare the file pointer
    FILE *filePointer ;
    
    // Open the existing file Sensor1_Data.csv using fopen()
    // in read mode using "r" attribute
    filePointer = fopen(filename, "r") ;
    
    float Temp_data, ChargeRate_data;
    float*Temperature;
    float*ChargeRate;
  
    for(int i=0; i<BUFFER_SIZE; i++)
    {
      fscanf(filePointer, "%f \t %f \n", &Temp_data,&ChargeRate_data);
      *(Temperature + i) = Temp_data;
      *(ChargeRate + i) = ChargeRate_data;
    }
    
    fclose(filePointer);
    
    return index_pos;
}

int m_readDataFromAFile(char * filename)
{   
    if(isFileOpenSuccessfully(filename))
    {
        return readData(filename);
    }
    else
    {
        return 0;
    }
}
