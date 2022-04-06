#include <stdio.h>
#include <string.h>
#include "sender.h"

// Declare the file pointer
FILE *filePointer ;

// Open the existing file SensorData.csv using fopen()
// in read mode using "r" attribute
filePointer = fopen("SensorData.csv", "r") ;

int isFileOpenSuccessfully()
{
    // Check if this filePointer is null
    // which maybe if the file does not exist
    if ( filePointer == NULL )
    {
        printf( "SensorData.csv file failed to open." ) ;
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
    reutrn 1;
}

int readData()
{
    return 50;
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
