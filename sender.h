#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//Requirement - 1
extern int accessFileForDataExtraction(char *filename, float *Temperature, float *ChargeRate);
//Requirement - 2
extern int isFileOpenSuccessfully(FILE *filePointer);
//Requirement - 3
extern int readDataAndSendToConsole(FILE *filePointer, float *Temperature, float *ChargeRate);
//Requirement - 4
extern int sendDataToConsole(float *Temperature, float *ChargeRate);

