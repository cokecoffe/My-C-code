#ifndef MAIN
#define MAIN

#include<stdio.h>
#define OK 1
#define ER -1
#define CREATE 1
#define DELETE 2
#define DISPLAY1 3
#define DISPLAY2 4
typedef struct memory        //空闲链表结构题
{
	int id;
	int memory_size;
	struct memory *pre;
	struct memory *next;
}Mem,*pMem;

typedef struct get_memory   //记录链表结构题
{
	pMem *get_addr;		//存放申请到的结点的地址
	struct get_memory *next;
}Get,*pGet;

#endif
