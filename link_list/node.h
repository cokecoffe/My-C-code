#ifndef NODE
#define NODE

#define OK 1
#define ER -1

#define INSERT 1
#define DELETE 2
#define SEARCH_1 3
#define SEARCH_2 4
#define PRINT 5
#include<stdio.h>

typedef struct student
{
	int num;
	int age;
	struct student *next;
	void (*stu_print)(struct student*);
	int (*stu_input)(struct student*);
}sStu,*pStu;

typedef struct list
{
	pStu head;
	int(*insert)(pStu,
				pStu,
				int(*pNameFind)(pStu,pStu),//查找姓名是否存在
				pStu(*pInsertPosition)(pStu,pStu));//查找插入点位置

	int(*del)(pStu,
				pStu,
				pStu(*pDelPosition)(pStu,pStu));

	void(*print)(struct list*);

	pStu (*search)(pStu pHead,int,int,pStu (*fun_search[])(pStu,int));
}sList,*pList;

#endif
