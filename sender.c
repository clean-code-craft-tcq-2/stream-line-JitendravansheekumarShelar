#include <string.h>
#include "sender.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 50

int isFileOpenSuccessfully(FILE *filePointer)
{    
    // Check if this filePointer is null
    // which maybe if the file does not exist
    return ( filePointer == NULL ) ? 0 : 1;
}


int readData(FILE *filePointer, float *Temperature, float *ChargeRate)
{
    float Temp_data = 0.0, ChargeRate_data = 0.0;
    int index_pos;
  
    for(index_pos=0; index_pos<BUFFER_SIZE; index_pos++)
    {
      fscanf(filePointer, "%f , %f \n", &Temp_data,&ChargeRate_data);
      *(Temperature + index_pos) = Temp_data;
      *(ChargeRate + index_pos) = ChargeRate_data;
    }
    
    fclose(filePointer);
    
    /* Every program you may run on the command line has 3 streams, STDIN, STDOUT and STDERR */
    fprintf(stdin, "%f , %f\n",Temperature,ChargeRate);
    
    return index_pos;
}

int m_readDataFromAFile(char * filename, float *Temperature, float *ChargeRate)
{  
    // Declare the file pointer
    FILE *filePointer ;
    
    // Open the existing file Sensor1_Data.csv using fopen()
    // in read mode using "r" attribute
    filePointer = fopen(filename, "r");
    
    return isFileOpenSuccessfully(filePointer) ? readData(filePointer,Temperature,ChargeRate) : 0;
}
