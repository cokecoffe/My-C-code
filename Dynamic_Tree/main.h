#ifndef MAIN
#define MAIN

#define INSERT 1
#define DELETE 2
#define PRINT 3
#define EXIT 4

#include"../malloc/create.h"
typedef struct data
{
	int num;
	struct data *par;
	struct data *lchild;
	struct data *rchild;
}Data,*pData;


#endif
