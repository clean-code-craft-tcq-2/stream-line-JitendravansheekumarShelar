#include <string.h>
#include "sender.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 50

// Declare the file pointer
FILE *filePointer ;

// Declare data buffer
float dataBuffer[BUFFER_SIZE] = {0};


int isFileOpenSuccessfully(char *filename)
{
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

int readData()
{
    //everytime function is called buffer is initialized to 0
    dataBuffer[BUFFER_SIZE] = {0};
    float value;
    int index_pos;
    
    for (int index_pos = 0; index_pos < BUFFER_SIZE ; index_pos++)
    {
        dataBuffer[index_pos] = value;
    }
    
    return index_pos;
}

int m_readDataFromAFile(char * filename)
{   
    if(isFileOpenSuccessfully(filename))
    {
        return readData();
    }
    else
    {
        return 0;
    }
}
