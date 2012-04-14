#include"listfun.h"

int NameFind(pStu pHead,pStu pInsert)
{
	pStu head=NULL;
	if(pHead->next==NULL)
	{
		return OK;
	}

	head = pHead->next;
	
	while(head != NULL)//遍历链表，如果有相同名字的返回ER
	{
		if(pInsert->num==head->num)
		{
			return ER;
		}
		head = head->next;
	}
	
	if(head->num!=pInsert->num&&head->next==NULL)//如果遍历到最后一个都没有相同，则返回OK，可以插入
	{
		return OK;
	}
	else
	{
		return ER;
	}

}

pStu InsertPosition(pStu pHead,pStu pInsert)   //插入位置查找函数
{
	pStu head = NULL;
//	head = pHead->next;//使head指向第一个数据结点
	if(pHead->next==NULL)
	{
		return pHead;
	}
	else
	{
		while((pHead->next!=NULL)&&(pHead->next->num)<(pInsert->num))
		{
			pHead = pHead->next;
		}
		return pHead;
	}
}

pStu DelPosition(pStu pHead,pStu pDel)		//删除位置查找函数
{
	pStu head=NULL;
	if(NULL==pHead)
	{
		return NULL;
	}
	head = pHead;
	while((head->next->num!=pDel->num)&&(head->next->next!=NULL))
	{
		head = head->next;
	}
	if((head->next->next==NULL)&&(head->next->num!=pDel->num))
	{
		return NULL;
	}
	return head;
}

pStu num_search(pStu pHead,int num)		//按照学号查找学生
{
	if(pHead==NULL)
	{
		return NULL;
	}
	
	while((pHead->next!=NULL)&&(num!=pHead->next->num))//如果最后一个节点是要查找的节点
	{
		pHead = pHead->next;	
	}
	return pHead->next;
}

pStu age_search(pStu pHead,int age)		 //按照年龄查找学生       
{
	pStu head = pHead->next;

	if(pHead==NULL)
	{
		return NULL;
	}
	
	while(age!=head->age)
	{
		head = head->next;
	}
	if((age!=head->age)&&(head->next==NULL))
	{
		return NULL;
	}
	return head;	
}

/*插入函数*/
int insert(pStu pHead,pStu pInsert,int (*NameFind)(pStu,pStu),pStu (*InsertPosition)(pStu,pStu))
{
	int ret=0;
	pStu in_posi=NULL;

	ret = NameFind(pHead,pInsert);	
	if(ER==ret)
	{
		printf("不能插入\n");
		return ER;
	}
	else{
			in_posi = InsertPosition(pHead,pInsert);
			pInsert->next = in_posi->next;
			in_posi->next = pInsert;
		}
	return OK;
}

/*删除函数*/
int del(pStu pHead,pStu pDel,pStu(*pDelPosition)(pStu,pStu))
{
	pStu del_posi=NULL;
	pStu temp=NULL;

	del_posi = pDelPosition(pHead,pDel);

	if(NULL==del_posi)
	{
		return ER;
	}
	
	printf("要删除的结点是num=%d\n",del_posi->next->num);

	temp = del_posi->next;//save the node to delete;

	del_posi->next = del_posi->next->next;
	free(temp);//free the delete
}

/*print*/
void print(struct list *p)
{
	pStu head = NULL;
	if(p->head->next == NULL)
	{
		printf("Null-node\n");
	}

	head = p->head->next;

	while(head->next!=NULL)
	{
		printf("num=%d,age=%d\n",head->num,head->age);
		head = head->next;
	}
	printf("num=%d,age=%d\n",head->num,head->age);

}

pStu search(pStu pHead,int flag,int age_num,pStu (*fun_search[])(pStu,int))
{
	return fun_search[flag](pHead,age_num);
}





