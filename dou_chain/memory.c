#include"memory.h"
#include<stdlib.h>


int init_memory(pMem *head)// 初始化双循环链接表
{
	dynamic_create((void**)head,sizeof(Mem));
	(*head)->id=0;
	(*head)->next = *head;
	(*head)->pre =*head;
	return OK;
}

int create_memory(pMem head,int n)//分配十个结构体空间
{
	int i;
	for(i=1;i<n+1;i++)
	{
		pMem new = NULL;
		dynamic_create((void**)&new,sizeof(Mem));
		
		new->id = i;
		new->memory_size = EACHMEMORY;

		new->pre = head->pre;
		new->next = head;
		head->pre->next= new;
		head->pre = new;
	}
}

int insert_own_memory(pMem head,pMem new)//空闲链表中插入新结点
{
	pMem temp;
	temp = head;
	pMem n_create;
	pMem insert = head;
	
	while(temp->next!=head)
	{
		if(temp->next->id == new->id)   //如果有相同的id结点，则更新空闲链表
		{
			temp->next->memory_size += new->memory_size;				
			return;
		}
		if(temp->next->id > new->id)//记录id比new小的前一个结点
		{
			insert = temp;
			break;
		}
		temp = temp->next;	
	}

	
		if(temp->next==head&&temp->id!=new->id)
		{
			insert = temp;
		}	
		
			dynamic_create((void**)&n_create,sizeof(Mem));//创建结点
			n_create->id = new->id;
			n_create->memory_size = new->memory_size;
		
			n_create->next = insert->next;// 插入结点
			n_create->pre = insert;

			insert->next->pre = n_create;
			insert->next = n_create;
			
	
}

int insert_memory(pMem head,pMem new)		//申请链表插入新结点
{
	pMem temp = head->next;
	pMem change;
	
	while(temp!=head && temp->id < new->id)
	{
		temp = temp->next;
	}	

	new->next = temp;
	new->pre = temp->pre;

	temp->pre->next = new;
	temp->pre = new;

}

int insert_temp_memory(pMem head,pMem new)		//临时链表插入新结点
{
	new->next = head;
	new->pre = head->pre;

	head->pre->next = new;
	head->pre = new;
}

int del_memory(pMem del)//从链表中删除结点
{	
		del->next->pre = del->pre;	
	    del->pre->next = del->next;
}

int updata_memory(pMem head,pMem max,pMem temp,int *size)
{
	pMem new = NULL;
	pMem will_del;

	if(*size > max->memory_size)//申请的大小大于已经有的大小
	{
		*size = *size - max->memory_size;

		del_memory(max);

		insert_temp_memory(temp,max);
	}
	else						//申请的小于空闲有的大小
		{
			max->memory_size -= *size;
			dynamic_create((void**)&new,sizeof(Mem));
			
			new->id = max->id;
			new->memory_size = *size;
			insert_temp_memory(temp,new);
			*size = 0;
		}
}

int del_applay_list(pMem apply,pMem del)//删除申请链表中的结点
{

	del->next->pre=del->pre;
	del->pre->next=del->next;
	free(del);

}







