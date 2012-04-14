#ifndef HASH
#define HASH
#include"main.h"

int Init_Hashtable(pHash1 *p);
int Init_Node(pNode *new,int num);
pHash2 SeekIndex(pHash1 head,int line,int colum);//定位到数据链头
int Insert_Node(pHash1 head,int line,int colum,pNode new);
int Find_Node(pHash1,int,int,int);

#endif
