#include"list.h"
#include<stdio.h>
int init_list(pData sl)//初始化数据链表
{
	int i,j;	
	pData new;
	pData tail = NULL;//尾插指针
	
	int temp_data=0;

	
	tail = sl;
	for(i=0;i<MAX_SIZE;i++) //输入数据
	{
		printf("input a num");
		scanf("%d",&temp_data);
		
		dynamic_create((void **)&new,sizeof(Data));
		
		new->num = temp_data;	//数据域初始化
		new->next = NULL;
		
		for(j=0;j<MAX_NUM_OF_KEY;j++)	//关键字部分初始化
		{
			new->keys[j] = temp_data%10;
			temp_data = temp_data/10;
		}
		tail->next = new;
		tail = new;
	}
}
int empty_list(pData p) //判断指针数组是否为空
{
	if(p == NULL)
	{	
		return EMPTY;
	}
	else 
	{
		return NO_EMPTY;
	}
}

int delete_list(pData head)//删除数据链表中第一个结点
{
	head->next = head->next->next;
}

pData find_end(pData head)//查找最后一个结点的位置
{
	while(head->next!=NULL)
	{
		head = head->next;
	}
	return head;
}

int print_data(pData sl)
{
	pData temp = sl;
	while(temp->next!=NULL)
	{
		printf("%d ",temp->next->num);
		temp = temp->next;
	}
	printf("\n");
}




