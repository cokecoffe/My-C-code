#ifndef MAIN
#define MAIN

#define MAX_NUM_OF_KEY 3
#define MAX_SIZE 5
#define RADIX 10
typedef struct data
{
	int num;
	int keys[MAX_NUM_OF_KEY];
	struct data *next;
}Data,*pData;

#endif
