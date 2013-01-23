#ifndef OPER
#define OPER

#define OK 1
#define ER -1
#define YES 1 
#define NO 0 
#define STACK_SIZE 20
#include"../malloc/create.h"
typedef struct
{
	int low;
	int high;
}Data,*pData;

typedef Data Elem;
typedef pData pElem;

typedef struct stack
{
	int top;
	pElem base;
	int stacksize;
}SqStack,*pSqStack;



int InitStack(pSqStack);
int GetTop(pSqStack,pElem);
int Pop(pSqStack);
int Push(pSqStack,Elem);
bool isEmptyStack(pSqStack);
bool isFullStack(pSqStack);

#endif
