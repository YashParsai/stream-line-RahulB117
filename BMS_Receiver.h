#include <stdio.h>

#define MAX_STREAMING_RANGE 50

void recieveDataFromConsole(char *recv_buff);
void extractTempData(int* temp_buff, char* recv_buff);
void extractSoCData(int* soc_buff, char* recv_buff);
int getMaxTemp(int*);
int getMinTemp(int*);
int getMaxSoC(int*);
int getMinSoC(int*);
void printSoCData(int* soc_buff);
void printTempData(int* temp_buff);
float calculateSimpleMovingAverageValue(int *inputBuffer,int sampleSize);
