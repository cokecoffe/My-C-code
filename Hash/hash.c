#include"hash.h"
#include"../malloc/create.h"
#include<stdio.h>

int Init_Hashtable(pHash1 *p)
{
	int i,j;
	pHash1 new;
	pHash2 colum;
	
	dynamic_create((void**)p,sizeof(Hash1));//初始化头结点
	(*p)->id = -1;
	(*p)->head = NULL;
	(*p)->next = NULL;
	
	for(i=0;i<NU_1;i++)						//初始化行
	{
		dynamic_create((void**)&new,sizeof(Hash1));
		new->id = i;
		new->next = (*p)->next;
		(*p)->next = new;
		new->head = NULL;
		
		for(j=0;j<NU_2+1;j++)					//初始化列
		{
			dynamic_create((void**)&colum,sizeof(Hash2));
			colum->id = j;
			
			colum->next = new->head;
			new->head = colum;
			colum->head = NULL;
		}
	}
	
}
int Init_Node(pNode *new,int num)			   //初始化新数据结点
{
	dynamic_create((void**)new,sizeof(Node));
	(*new)->data = num;
	(*new)->next = NULL;
}

pHash2 SeekIndex(pHash1 head,int line,int colum)//定位到数据链头
{
	pHash1 temp_line;
	pHash2 temp_colum;
	
	temp_line = head->next;
	while(line!=temp_line->id)				//找到行指针
	{
		temp_line = temp_line->next;
	}
	
	temp_colum = temp_line->head;			//找到列指针
	while(colum!=temp_colum->id)
	{
		temp_colum = temp_colum->next;
	}
	return temp_colum;
	
}


int Insert_Node(pHash1 head,int line,int colum,pNode new)
{
	pHash2 temp_colum;
	
	temp_colum = SeekIndex(head,line,colum);
	
	new->next = temp_colum->head;
	temp_colum->head = new;
}

int Find_Node(pHash1 head,int line,int colum,int num)
{
	int times=0;
	pHash2 temp_colum;
	pNode pdata;
	
	temp_colum = SeekIndex(head,line,colum);	
	pdata = temp_colum->head;
	
	while(pdata!=NULL)
	{
		if(pdata->data==num)
		{
			times++;
		}
		pdata = pdata->next;
	}
	return times;
}

