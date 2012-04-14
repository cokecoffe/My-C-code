#ifndef MAIN
#define MAIN


#define NU_1 5
#define NU_2 7

typedef struct node        //数据结点
{
	int data;
	struct node *next;
}Node,*pNode;

typedef struct HashList_2   //第2次哈希的结点
{
	int id;
	pNode head;
	struct HashList_2 *next;
}Hash2,*pHash2;

typedef struct HashList_1   //第1次哈希的结点
{
	int id;
	pHash2 head;
	struct HashList_1 *next;
}Hash1,*pHash1;

#endif
