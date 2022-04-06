#include <string.h>
#include "sender.h"

// Declare the file pointer
FILE *filePointer ;

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
    return 1;
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
