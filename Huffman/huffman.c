#include<stdio.h>
#include<string.h>
#include"huffman.h"

#include"../malloc/create.h"

int Select(pHuff T,int *min,int *sec,int num)//选择两个最小的，父指针为NULL的结点
{
	int i;
	int m_index = 0;
	int s_index = 0;
	
	for(i=0;i<num;i++)  // 找 最 小 的 数,
	{
		if(T[i].par==0)
		{
			m_index = i;
			break;
		}
	}

	for(i=0;i<num;i++)
	{
		if(T[i].par == 0 && T[i].count!=0 && T[i].count < T[m_index].count)
		{
			m_index = i;
		}
	}
	
	for(i=0;i<num;i++)  // 找 次 小 的 数,
	{
		if(T[i].par==0&&i!=m_index)
		{
			s_index = i;
			break;
		}
	}
	
	for(i=0;i<num;i++)
	{
		if( T[i].par == 0 && T[i].count!=0 && T[i].count < T[s_index].count && i!=m_index)
		{
			s_index = i;
		}
	}
	
	*min = m_index;
	*sec = s_index;
	
}

/*建立Huffman树*/
CreateHuffTable(pData alp_num,pHuff *huffman,int num)
{
	int i;
	int m;
	int min,sec;
	pData temp;
	*huffman = (pHuff)malloc((2*num-1)*sizeof(Huff));
	
	temp = alp_num->next;
	for(i=num-1;i>=0;i--)							//将叶子结点初始化
	{
		(*huffman)[i].alp = temp->data;
		(*huffman)[i].count = temp->num;
		temp = temp->next;
	}
		
	m = 2*num-1;
	for(i=num;i<m;i++)
	{
		Select(*huffman,&min,&sec,m);//选择两个最小的，父指针为NULL的结点
		(*huffman)[min].par = i;
		(*huffman)[sec].par = i;
		(*huffman)[i].lchild = min;
		(*huffman)[i].rchild = sec;
		(*huffman)[i].count =(*huffman)[min].count+(*huffman)[sec].count;
	}
	
}	

/*求每个字母的Huffman编码*/
HuffmanCode(pHuff T,char **alp_code,int num)
{
	int i,j;
	int start;
	char *work;
	work = (char *)malloc(num*sizeof(char));
	if(work==NULL)
	{
		printf("create memory err\n");
		return;
	}
	work[num-1] = '\0';

	for(i=0;i<num;i++)
	{
		start = num-1;				//编码結束位置
		j=i;
		while(T[j].par!=0)
		{
			if(T[T[j].par].lchild == j)
			{
				work[--start] = '0';
			}
			else
			{
				work[--start] = '1';
			}
			j = T[j].par;
		}
	
		alp_code[i] = (char*)malloc((num-start)*sizeof(char));
     	strcpy(alp_code[i],&work[start]);//从work中复制到alp_code中
	}
	
	free(work);
}






