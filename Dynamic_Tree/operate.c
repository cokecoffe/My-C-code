#include"operate.h"
#include<stdio.h>
int	init_elem(pData *sl)
{
	dynamic_create((void**)sl,sizeof(Data));
	(*sl)->num = 0;
	(*sl)->par = NULL;
	(*sl)->lchild = NULL;
	(*sl)->rchild = NULL;
}
/*查找要插入的父结点或者要删除的结点*/
int Find_Point(pData sl,int new_del,pData *index)
{
	if(new_del < sl->num)
	{
		while(new_del < sl->num && sl->lchild!=NULL)
		{
			sl = sl->lchild;
		}
		if(new_del > sl->num)
		{
			Find_Point(sl,new_del,index);
		}
		else
			{
				*index = sl;
				return LEFT;
			}
	}
	else{	
			while(new_del > sl->num && sl->rchild!=NULL)
			{
				sl = sl->rchild;
			}
			if(new_del < sl->num)
			{
				Find_Point(sl,new_del,index);
			}
			else
				{
					*index = sl;
					return RIGHT;
				}
		}
}
/*插入新结点*/
int insert_tree(pData sl,pData new)
{
	pData index;
	int ret;
	ret = Find_Point(sl,new->num,&index);
	if(ret == LEFT)
	{
		index->lchild = new;
		new ->par = index;
	}
	else{
			index->rchild = new;
			new ->par = index;
		}
}
/*删除一个结点*/
int delete_tree(pData *sl,int del)
{
	pData will_del;
	pData temp_rf;
	int ret;
	ret = Find_Point(*sl,del,&will_del);
		
	if(will_del->rchild == NULL && will_del->lchild==NULL)//删除的是叶子结点
	{
		if(ret==LEFT)
		{
			will_del->par->lchild = NULL;
			return OK;
		}
		else if(ret == RIGHT)
			{
				will_del->par->rchild = NULL;
				return OK;
			}
	}
	
	if(will_del->par==NULL)//删除根结点 
	{
		if(will_del->lchild == NULL)   //左空
		{
			*sl = will_del->rchild;
			will_del->rchild->par = *sl;
			return OK;
		}
		else if(will_del->rchild == NULL)  //右空
			{
				*sl = will_del->lchild;
				will_del->lchild->par = *sl;
				return OK;
			}
			else                   //左右非空
				{
					*sl = will_del->lchild;
					temp_rf = *sl;
					
					while(temp_rf->rchild!=NULL)
					{
						temp_rf = temp_rf->rchild;
					}
					temp_rf->rchild = will_del->rchild;
					will_del->rchild->par = temp_rf;
					return OK;
				}
			
	}
	
	
	if(ret==LEFT  ) //要删除的结点是某个结点的左孩子
	{
		if( will_del->lchild!=NULL)
		{
			will_del->par->lchild = will_del->lchild;
			will_del->lchild->par = will_del->par;
		}
		else  //左孩子为空
			{
				will_del->rchild->par = will_del->par->lchild;
				will_del->par->lchild = will_del->rchild;
				return OK;
			}
	}
	else if(ret == RIGHT) //要删除的结点是某个结点的右孩
		{
			if(will_del->lchild!=NULL)
			{
				will_del->par->rchild = will_del->lchild;
				will_del->lchild->par = will_del->par;	
			}
			else//左孩子为空 
				{
					will_del->rchild->par = will_del->par->rchild;
					will_del->par->rchild = will_del->rchild;
					return OK;
				}
		}	
			
	if(will_del->rchild !=NULL)//要删除的结点有左右孩子
	{
			temp_rf = will_del->lchild;//为右孩子寻找挂载点 
			while(temp_rf->rchild!=NULL)
			{
				temp_rf = temp_rf->rchild;
			}
			temp_rf->rchild = will_del->rchild;
			will_del->rchild->par = temp_rf;
	}
	else                    //要删除的结点有左孩子,没有右孩子  
	{
		;
	}			
	free(will_del);
}

int Print_tree(pData sl)
{
	if(sl->lchild!=NULL)
	{
		Print_tree(sl->lchild);
	}
	if(sl!=NULL)
	{
			printf("%d ",sl->num);
	}
	if(sl->rchild!=NULL)
	{	
		Print_tree(sl->rchild);
	}
}
