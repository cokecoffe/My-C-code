#ifndef OPER
#define OPER

#define OK 1
#define ER -1
#define EMPTY -2
#define FULL -1
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
int EmptyStack(pSqStack);
int FullStack(pSqStack);

#endif
