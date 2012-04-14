#ifndef QUEUE
#define QUEUE

#define OK 1
#define ER -1
#define MAXSIZE 5


typedef int QElemType;

typedef struct Qnode
{
	QElemType data;
	struct Qnode *next;
}QNode,*pQNode;

typedef struct
{
	pQNode base;
	int front;
	int rear;
}SqQueue;

int InitQueue(SqQueue *);//初始化队列
int EnQueue(SqQueue *,QElemType);//进队列
int DeQueue(SqQueue *,QElemType*);//出队列
#endif
