#include <string.h>
#include <stdio.h>
#include <stdlib.h>

extern int readData(FILE *filePointer, float *Temperature, float *ChargeRate);
extern int sendDataToConsole( float *Temperature, float *ChargeRate);
extern int accessFileForDataExtraction(char *filename, float *Temperature, float *ChargeRate);
extern int isFileOpenSuccessfully(FILE *filePointer);

