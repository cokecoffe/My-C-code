#include"operate.h"


/*init every data*/
int init_elem(pData *elem)
{
	int i;
	dynamic_create((void**)elem,SIZE*sizeof(Data));
	
	for(i=0;i<SIZE;i++)
	{
		(*elem)[i].num = EMPTY;
		(*elem)[i].par = EMPTY;
		(*elem)[i].lchild = EMPTY;
		(*elem)[i].rchild = EMPTY;
	}
}
/*input data*/
int intput_elem(pData elem)
{
	int i;
	printf("input %d data:",SIZE);
	
	for(i=0;i<SIZE;i++)
	{
		scanf("%d",&(elem[i].num));
	}
	printf("input over\n");
}

int create_tree(pData elem)
{
	int i,j;
	
	for(i=1;i<SIZE;i++)
	{
		for(j=0;j<i;j++)
		{
			if(elem[i].num<elem[j].num) 
			{
				if(elem[j].lchild==EMPTY)
				{
					elem[j].lchild = i;
					elem[i].par = j;
					break;
				}
				else
				{
					j = elem[j].lchild-1;
				}
			}
			else	
			 {
			 	if(elem[j].rchild==EMPTY)
				{
					elem[j].rchild = i;
					elem[i].par = j;
					break;
				}
				else
				{
					j = elem[j].rchild-1;
				}
			}		
		}
	}
}

int find_index(pData elem,int num)
{
	int i;
	for(i=0;i<SIZE;i++)
	{
		if(elem[i].num == num)
		{
			return i;
		}
	}
}
/*delete data*/
int delete_elem(pData elem,int index)
{
	int par=0;
	int temp_lf;
	int temp_rf;
	
	if(elem[index].par == EMPTY)//delete root
	{

		if(elem[index].lchild != EMPTY)
		{
			temp_lf = elem[index].lchild;
						
			elem[temp_lf].par = EMPTY;
		
			while(elem[temp_lf].rchild!=EMPTY)
			{		
				temp_lf = elem[temp_lf].rchild;
			}	
			elem[temp_lf].rchild = elem[index].rchild;	
			return OK;
		}
		else{
				printf("left child is EMPTY\n");
			}
	}
	
	if(elem[index].lchild==EMPTY&&elem[index].rchild==EMPTY)//yezi jiedian
	{
		par = elem[index].par;
		if(elem[par].rchild == index)
		{
			elem[par].rchild = EMPTY;
		}
		else
		{
			elem[par].lchild = EMPTY;
		}
	}
			
	if(elem[index].lchild!=EMPTY||elem[index].rchild!=EMPTY)
	{
		if(elem[index].num<elem[elem[index].par].num)//par>del
		{
			elem[elem[index].par].lchild = elem[index].lchild;
			elem[elem[index].lchild].par = elem[index].par;
		}
		else
		{
			elem[elem[index].par].rchild = elem[index].lchild;
			elem[elem[index].lchild].par = elem[index].par;
		}
		
		if(elem[index].rchild!=EMPTY)
		{
			temp_rf = elem[index].lchild;
			
			while(elem[temp_rf].rchild!=EMPTY)
			{
				temp_rf = elem[temp_rf].rchild;
			}
			
			elem[temp_rf].rchild = elem[index].rchild;
			elem[elem[index].rchild].par = temp_rf;
		}
	}
		
}

int	output_tree(pData elem)
{
	int i;
	printf("id    num    par   lchild   rchild \n");
	for(i=0;i<SIZE;i++)
	{		
		printf("%d\t%d\t%d\t%d\t%d\n",i,elem[i].num,elem[i].par,elem[i].lchild,elem[i].rchild);
	}
}








