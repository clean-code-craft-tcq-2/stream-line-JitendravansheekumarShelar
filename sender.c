#include <string.h>
#include "sender.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 50

// Declare the file pointer
FILE *filePointer ;

// Declare data buffer
float dataBuffer[BUFFER_SIZE] = {0};

// Open the existing file Sensor1_Data.csv using fopen()
// in read mode using "r" attribute
filePointer = fopen("Sensor1_Data.csv", "r") ;

int isFileOpenSuccessfully()
{
    // Check if this filePointer is null
    // which maybe if the file does not exist
    if ( filePointer == NULL )
    {
        printf( "Sensor1_Data.csv file failed to open." ) ;
        return 0;
    }
    else
    {       
        printf("The file is now opened.\n") ;
        return 1;
    }
}

int isDataReadSuccessfully()
{
    if(m_readDataFromAFile())
        return 1;
    else
        return 0;
}

int readData()
{
    //everytime function is called buffer is initialized to 0
    dataBuffer[BUFFER_SIZE] = {0}
    float value;
    
    for (index = 0; index < BUFFER_SIZE ; index++)
    {
        dataBuffer[index] = value;
    }
    
    return index;
}

int m_readDataFromAFile()
{   
    if(isFileOpenSuccessfully())
    {
        return readData();
    }
    else
    {
        return 0;
    }
}
