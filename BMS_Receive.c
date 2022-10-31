#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BMS_Receiver.h"


void recieveDataFromConsole(char *recv_buff)

{
	int reading=0;
	char line[10]={0};
	char *buff = recv_buff;

	for(reading; reading < MAX_STREAMING_RANGE; reading++) 
	{
		scanf("%s",line);
    		strcpy(buff,line);
		buff = strchr(recv_buff,0); 
	}
}

void extractTempData(int* temp_buff, char* recv_buff)
{
	int index=0;
	char* temp_ptr = recv_buff;
	char* reading;
	int temp;

	for(index; index < MAX_STREAMING_RANGE; index++)
	{
		reading = strtok(temp_ptr,",");
		reading = strtok(NULL,",");

		temp = atoi(reading);
		temp_buff[index] = temp;
		temp_ptr = strchr(recv_buff, '\n');
	}
}



void extractSoCData(int* soc_buff, char* recv_buff)
{
	int index=0;
	char* soc_ptr = recv_buff;
	char* reading;
	int soc;

	for(index; index < MAX_STREAMING_RANGE; index++)
	{
		reading = strtok(soc_ptr,",");
		reading = strtok(NULL,",");
		reading = strtok(NULL,",");

		soc = atoi(reading);
		soc_buff[index] = soc;
		soc_ptr = strchr(recv_buff, '\n');
	}		
}



int getMaxTemp(int* temp_buff)
{
	int temp_max=temp_buff[0];
	int index;

	for(index = 0; index < MAX_STREAMING_RANGE; index++)
  	{
		if(temp_max < temp_buff[index])
		{
			temp_max = temp_buff[index];
		}
	}
	return temp_max;
}



int getMinTemp(int* temp_buff)
{
	int temp_min=temp_buff[0];
	int index;

	for(index = 0; index < MAX_STREAMING_RANGE; index++)
	{
		if(temp_min > temp_buff[index])
		{
			temp_min = temp_buff[index];
		}
	}
	return temp_min;
}



int getMaxSoC(int* soc_buff)
{
	int soc_max=soc_buff[0];
	int index;

	for(index = 0; index < MAX_STREAMING_RANGE; index++)
	{
		if(soc_max < soc_buff[index])
		{
			soc_max = soc_buff[index];
		}
	}
	return soc_max;
}

int getMinSoC(int* soc_buff)
{
	int soc_min=soc_buff[0];
	int index;

	for(index = 0; index < MAX_STREAMING_RANGE; index++)
	{
		if(soc_min > soc_buff[index])
		{
			soc_min = soc_buff[index];
		}
	}
	return soc_min;
}



void printTempData(int* temp_buff)
{
	int index;
  
 	printf("Printing received TEMP DATA:\n");
	for(index =0 ; index < MAX_STREAMING_RANGE; index++)
	{
		printf("%d\n",temp_buff[index]);
	}
}


void printSoCData(int* soc_buff)
{
	int index;

	printf("Printing received SOC DATA:\n");
	for(index =0 ; index < MAX_STREAMING_RANGE; index++)
	{
		printf("%d\n",soc_buff[index]);
	}
}

float calculateSimpleMovingAverageValue(int *inputBuffer,int sampleSize)
{
    	float simpleMovingAverage;
	int sum = 0;
	int temp;
	int sample = 0;

	for(; sample < sampleSize ; sample++)
	{
		temp = inputBuffer[sample];
	    	sum = temp+sum;
	}
	
	simpleMovingAverage = sum/sampleSize;
	return simpleMovingAverage;
}
