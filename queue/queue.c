#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

int InitQueue(SqQueue *Q)//初始化队列
{
	Q->base = (pQNode)malloc(MAXSIZE*sizeof(QNode));
	if(!Q->base)
	{
		printf("分配空间失败\n");
		return ER;
	}
	Q->rear = Q->front = 0;
	return OK;
}
int EnQueue(SqQueue *Q,QElemType e)//进队列
{
	if((Q->rear+1)%MAXSIZE == Q->front)
	{
		printf("queue full\n");
		return ER;
	}
	Q->base[Q->rear].data = e;
	Q->rear = (Q->rear+1)%MAXSIZE;
	return OK;
}
int DeQueue(SqQueue *Q,QElemType *e)//出队列
{
	if(Q->rear == Q->front)
	{
		printf("queue empty\n");
		return ER;
	}
	*e = Q->base[Q->front].data;
	Q->front = (Q->front+1)%MAXSIZE;
	return OK;
}

