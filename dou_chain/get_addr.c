#include"get_addr.h"
#include"main.h"

int init_get_addr(pGet *head)
{
	dynamic_create((void**)head,sizeof(Get));

	(*head)->next = NULL;
	return OK;
}
/*向记录链表中插入新结点*/
int insert_get_addr(pGet record,pMem temp_list ,int index)
{
		pGet new;
		pMem temp = temp_list;
		int i=0;
		dynamic_create((void **)&new,sizeof(Get));

		dynamic_create((void**)&(new->get_addr),(index+1)*sizeof(pMem));//开辟指针数组
		
		i=0;
		while(temp_list->next!=temp)   //将临时链表中的结构体地址赋值给记录联表中的指针数组
		{	
		    (new->get_addr)[i] = temp_list->next;
			temp_list = temp_list->next;
			i++;
		}
		new->get_addr[i]=NULL;//指针数组最后一个位置设空
		new->next = NULL;
		
		while(record->next!=NULL)//指针移到记录链表最后
		{
			record = record->next;
		}

		record->next = new;

}

pMem *get_record(pGet p)
{
	return p->get_addr;
}






