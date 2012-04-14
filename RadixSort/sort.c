#include"sort.h"
#include<stdio.h>
#include"list.h"

void Distribute(pData r,int j,pData index[])
{
	int i;
	int ret;
	pData add_temp = NULL;
	pData del_temp;
	int key;

	for(i=0;i<RADIX;i++)
	{
		index[i] = NULL;//初始化指针数组
	}

	while(r->next!=NULL)
	{
		key = r->next->keys[j];//获取第index个关键字

		ret = empty_list(index[key]);//判断指针是否为空
		
		if(EMPTY==ret)
		{	
			index[key] = r->next;//如果指针为空,则将指针指向结点
		}
		    else
			{
			
				add_temp = find_end(index[key]);//返回最后结点位置
				add_temp->next = r->next;
			}
		del_temp = r->next;//record the first_addr
		delete_list(r);//从数据链表中删除第一个结点
		del_temp->next = NULL;
	}
	
}
void Collect(pData r,int j,pData index[])
{
	int i;
	pData tail = r;//末尾指针

	for(i=0;i<RADIX;i++)
	{
		if(index[i]!=NULL)
		{
			tail->next = index[i];
			while(tail->next!=NULL)
			{
				tail = tail ->next;
			}
		}
	}
}






















