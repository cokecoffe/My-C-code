#include<stdio.h>
#include"tree.h"
#include"../stack/stack.h"
#include"main.h"
int init_node(pData *new,char ch)
{
	dynamic_create((void**)new,sizeof(Data));//初始化一个结点 
	(*new)->alp = ch;
	(*new)->Lchild = *new;
	(*new)->Rchild = *new;
	(*new)->par = NULL;
}

int PreCreateTree(pData *T)
{
	char ch;
	int ret;
	SqStack sta;
	pData get_elem = NULL;
	pData new;
	
	InitStack(&sta);
	printf("input root node\n");
	scanf("%c",&ch);
	getchar();

	dynamic_create((void**)T,sizeof(Data));//建立根
	init_node(T,ch);
	
	ret = EmptyStack(&sta);
	if(ret==EMPTY)
	{
		Push(&sta,(Elem)(*T));
	}
			
	while(EMPTY!=EmptyStack(&sta))
	{
		GetTop(&sta,(pElem)(&get_elem));			//取栈顶元素
		get_elem = (pData)get_elem;

		if(get_elem->Lchild==get_elem)//如果左孩子没处理
		{
			printf("input a alp\n");
			
			scanf("%c",&ch);
			getchar();
			if(' '==ch)
			{
				get_elem->Lchild =  NULL;
			}
			else{
					init_node(&new,ch);
					new->par = get_elem;
					get_elem->Lchild = new;
					Push(&sta,(Elem)new);
				}
		}
		else if(get_elem->Rchild==get_elem)//右孩子没处理 
				{
					printf("input a alp\n");
					scanf("%c",&ch);
					getchar();
					if(' '==ch)
					{
						get_elem->Rchild =  NULL;
					}
					else{
							init_node(&new,ch);
							new->par = get_elem;
							get_elem->Rchild = new;
							Push(&sta,(Elem)new);
						}	
		}else if(get_elem->Lchild!=get_elem && get_elem->Rchild!=get_elem)//左右孩子处理过了 
			{
				Pop(&sta);
			}
	}
}


int PreTraverse(pData T)
{
	SqStack sta;
	pData p;
	
	InitStack(&sta);
	if(T!=NULL)              //root
	{
		Push(&sta,(Elem)T);
	}
	else{
			printf("empty tree\n");
		}

	while(EMPTY != EmptyStack(&sta))
	{
		GetTop(&sta,(pElem)(&p));
		p = (pData)p;	
		printf("%c",p->alp);
		Pop(&sta);
		if(p->Rchild!=NULL)
		{
			Push(&sta,(Elem)(p->Rchild));
		}
		if(p->Lchild!=NULL)
		{
			Push(&sta,(Elem)(p->Lchild));
		}
	}
	printf("\n");
}

int MidTraverse(pData T)
{
	SqStack sta;
	pData p;
	
	InitStack(&sta);
	
	Push(&sta,(Elem)T);
	while(EMPTY!=EmptyStack(&sta))
	{
		
		while(GetTop(&sta,(pElem)&p)==OK && p!=NULL)
		{
			Push(&sta,(Elem)(((pData)p)->Lchild));
		}
		Pop(&sta);
		if(EMPTY!=EmptyStack(&sta))
		{
			GetTop(&sta,(pElem)&p);
			p = (pData)p;
			printf("%c",p->alp);
			Pop(&sta);
			Push(&sta,(Elem)(p->Rchild));
		}	
	}
	printf("\n");
	return OK;
}

int LastTravers(pData T)
{
	SqStack sta;
	pData get;
	pData p;
	pData temp=NULL;//pre print
	
	InitStack(&sta);	
	p = T;
	while(p||EMPTY!=EmptyStack(&sta))
	{
		if(p!=NULL)
		{
			Push(&sta,(Elem)p);
			p = p->Lchild;
		}
		else{
				GetTop(&sta,(pElem)(&get));
				Pop(&sta);
				if(get->Rchild==NULL)
				{
					printf("%c",get->alp);
					temp = get;
				}
				else{
						Push(&sta,(pElem)get);
						if(temp==get->Rchild)
						{
								printf("%c",get->alp);
								temp = get;
								p = NULL;
								continue;
						}
						p = get->Rchild;					
					}
			}
	}
	
	
}
