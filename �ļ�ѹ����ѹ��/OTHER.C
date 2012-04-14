#include<stdlib.h>
#include<stdio.h>
#include"main.h"
/*查 找 对 应 的 字 母*/
int Find_code(pData alp_num,char ch)
{
	int i;
	pData temp;
	temp = alp_num->next;
	for(i=0;temp!=NULL;i++)
	{
		if(temp->data==ch)
		{
			return i;
		}
		temp = temp->next;
	}
	
	if(temp==NULL)
	{
		printf("find err\n");
		return ER;
	}
}
/* 统计字符 */
int CountChar(FILE *id,pData *p)
{
	char ch;
	int num=0;//记录字母种类个数
	pData temp;
	pData new;
	
	*p = (pData)malloc(sizeof(Data));//开辟头结点

	if(*p==NULL)
	{
		printf("开辟空间失败\n");
		return ER;
	}
	(*p)->next = NULL;

	while(0!=fread(&ch,1,1,id)&&ch!='#')
	{
		temp = (*p)->next;
		while(temp!=NULL)//如果又相符合的记录，count++
		{
			if(temp->data == ch)
			{
				temp->num++;
				break;
			}
			temp = temp->next;
		}
		if(NULL==temp)//没有找到相符合的记录
		{
			new = (pData)malloc(sizeof(Data));
			new->data = ch;
			new->num = 1;
			
			new->next = (*p)->next;//采用头插法插入新结点
			(*p)->next = new;
		}
	}
	
	temp = (*p)->next;
	while(temp!=NULL)
	{
		num++;
		temp = temp->next;
	}
	
	return num;
}
/*把 Huffman 树 写 入 文 件*/
int PushHuffman(FILE *id,pHuff T,int num_of_huff)
{
	fwrite(T,num_of_huff*sizeof(Huff),1,id);
}
/*把 Huffman code 写 入 文 件*/
int PushHuffCode(FILE *id,FILE *w_id,pData alp_num,char **alp_code)
{
	char ch;
	char temp;			//写入文件的中间变量
	int index; 
	int i=0,j=0;
	int num;
	char flag;//标记最有8位几位有效
	
	while(fread(&ch,1,1,id) && ch!='#')
	{
		i=0;
		index = Find_code(alp_num,ch);//查找字母表中对应位置
		if(index == ER)
		{
			return ER;
		}
		while(alp_code[index][i]!='\0')
		{
			num = (alp_code[index][i++] == '1'?1:0);
			temp = temp&num;
			temp = temp<<1;
			j++;
			if(j%7==0)
			{
				fwrite(&temp,1,1,w_id);
			}	
		}
	}
	flag = j%7;
	
	fwrite(&flag,1,1,w_id);
	fwrite(&temp,1,1,w_id);
}
/*从 文 件 中 读 出 Huffman 树*/
int Get_Huffman(pHuff *T,FILE *r_id)
{
	pHuff get;
	int i;
	fread(get,sizeof(Huff),1,r_id);
	for(i=1;get->par!=0;i++)
	{
		fread(get,sizeof(Huff),1,r_id);	   //统计Huffman记录个数
	}
	
	
	
	
	
}
