#include<stdio.h>
#include"stack.h"
#include"main.h"

int InitStack(pSqStack s)
{
	int ret;
	ret = dynamic_create((void**)&(s->base),STACK_SIZE*sizeof(Elem));
	if(ER==ret)
	{
		printf("create stack err\n");
		return ER;
	}
	s->top = 0;
	s->stacksize = STACK_SIZE;
	return OK;
}
int EmptyStack(pSqStack s)
{
	if(s->top==0)
	{
		return EMPTY;
	}
}
int FullStack(pSqStack s)
{
	if(s->top == s->stacksize)
	{
		printf("stack full");
		return FULL;
	}
}

int GetTop(pSqStack s,pElem e)
{
	int ret;
	ret = EmptyStack(s);
	if(EMPTY==ret)
	{
		printf("栈空,无法取栈顶元素\n");
		return ER;
	}
	else{
			*e = (s->base)[s->top-1];
			return OK;
		}
}

int Pop(pSqStack s)
{
	int ret;
	ret = EmptyStack(s);
	if(EMPTY==ret)
	{
		printf("栈空,无法弹栈\n");
		return ER;
	}
	else{
			s->top--;
			return OK;
		}
}

int Push(pSqStack s,Elem e)
{
	int ret;
	ret = FullStack(s);
	
	if(ret == FULL)
	{
		printf("Push err\n");
		return ER;
	}
	(s->base)[s->top] = e;
	s->top++;
		
	return OK;
}






