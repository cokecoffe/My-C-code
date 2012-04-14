#ifndef MAIN
#define MAIN

#define ER -1
#define OK 1
typedef struct data_str			//保存字母及字母个数
{
	char data;
	int num;
	struct data_str *next;
}Data,*pData;

typedef struct
{
	char alp;
	int count;
	int lchild,rchild,par;
}Huff,*pHuff;

#endif
