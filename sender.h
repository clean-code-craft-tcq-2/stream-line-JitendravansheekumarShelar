#include <string.h>
#include <stdio.h>
#include <stdlib.h>

extern int readData(FILE *filePointer, float *Temperature, float *ChargeRate);
extern int m_readDataFromAFile(char *filename, float *Temperature, float *ChargeRate);
extern int isFileOpenSuccessfully(FILE *filePointer);

