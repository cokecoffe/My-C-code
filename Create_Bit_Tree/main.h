#ifndef MAIN
#define MAIN

#include<stdio.h>

typedef struct data
{
	char alp;
	struct data *par;
	struct data *Lchild;
	struct data *Rchild;
}Data,*pData;

#endif
