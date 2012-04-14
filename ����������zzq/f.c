#include "main.h"
int CreateNode(pTree *pTmp,char cTmp)
{
	*pTmp = (pTree )malloc(sizeof(sTree));
	if(NULL == *pTmp)
	{
		return ERR;
	}
	(*pTmp)->c = cTmp; 
	(*pTmp)->w = 1; 
	(*pTmp)->pPar = NULL;
	(*pTmp)->pLef = NULL;
	(*pTmp)->pRit = NULL;
	(*pTmp)->pNext = NULL;
	
	return SUC;
}

int CreateCodeNode(pCode *pTmp,char code)
{
	*pTmp = (pCode)malloc(sizeof(sCode));
	if(NULL == *pTmp)
	{
		return ERR;
	}
	(*pTmp)->c = code;
	return SUC;
}
int InsertNode(pCode pCodeHead,pCode pCodeTmp)
{
	list_add(&(pCodeTmp->list),&(pCodeHead->list));
	return SUC;
}
/**/
int TravCodeChain(pCode pCodeHead,int fid)//遍历代码，存入文件
{
	pCode pTmp;
	struct list_head* pos;
	int ret;
	char c = '\n',arr[4]= "(c)-";

	arr[1] = pCodeHead->c;
	ret = write(fid,arr,4);
	if(-1 == ret)
	{
		printf("写入错误\n");
		return ERR;
	}
	printf("(%c)-",pCodeHead->c);
	list_for_each(pos,&pCodeHead->list)
	{
		pTmp = list_entry(pos,sCode,list);
		ret = write(fid,&pTmp->c,1);
		if(-1 == ret)
		{
			printf("写入错误\n");
			return ERR;
		}	
		printf("(%c)-",pTmp->c);
	}
	ret = write(fid,&c,1);
	if(-1 == ret)
	{
		printf("写入错误\n");
		return ERR;
	}	
	printf("%c",c);
	return SUC;
}

int Getcode(pTree pHead,int fid)//产生哈夫曼编码
{
	pTree pLeaf = pHead->pNext;
	pTree pTmp,pPar;
	pCode pCodeTmp,pCodeHead;
	int ret;
	struct list_head *pos,*q;


	while(NULL != pLeaf)
	{	ret = CreateCodeNode(&pCodeHead,'-');
		if(ERR == ret)
		{
			return ERR;
		}
		INIT_LIST_HEAD(&pCodeHead->list); /*初始化链表头*/
		if(NULL != pLeaf->pRit || NULL != pLeaf->pLef)
		{
			break;
		}
		pTmp  = pLeaf;
		pCodeHead->c = pTmp->c;
		while(NULL != pTmp->pPar)
		{
			pPar = pTmp->pPar;
			if(pPar->pLef == pTmp)
			{
				ret = CreateCodeNode(&pCodeTmp,'1');
				if(ERR == ret)
				{
					return ERR;
				}
				InsertNode(pCodeHead,pCodeTmp);
			}
			else if(pPar->pRit == pTmp)
			{
				ret = CreateCodeNode(&pCodeTmp,'0');
				if(ERR == ret)
				{
					return ERR;
				}
				InsertNode(pCodeHead,pCodeTmp);
			}
			else
			{
				return ERR;
			}
			pTmp = pPar;
		}//生成代码成功
		TravCodeChain(pCodeHead,fid);//遍历代码，存入文件
		list_for_each_safe(pos,q,&pCodeHead->list);
		{
			pCodeTmp = list_entry(pos,sCode,list);
			list_del(pos);
			free(pCodeTmp);
		}
		//free(pCodeHead);
		pLeaf = pLeaf->pNext;
	}
	return SUC;	
}
int FunOpar(pTree pHead,char cTmp)//产生叶子节点
{
	pTree pTmp;
	int ret;

	pTmp = pHead;
	if('\n' == cTmp)
	{
		return SUC;
	}
	while(NULL != pTmp->pNext)
	{
		pTmp = pTmp->pNext;
		if(pTmp->c == cTmp)
		{
			pTmp->w += 1;
			return SUC;
		}		
	}
	ret = CreateNode(&pTmp->pNext,cTmp);
	if(ERR == ret)
	{
		return ERR;
	}
	
	return SUC;
}
pTree GetFirstAvaiNode(pTree pTmp)//找到第一个可用节点
{
	while(NULL != pTmp)
		{
			if(NULL == pTmp->pPar)
			{
				break;
			}
			pTmp = pTmp->pNext;
		}
	return pTmp;
}
void Swep(pTree *pSec,pTree *pFir)//交换指针
{
	pTree pSwap;

	pSwap = *pSec;
	*pSec = *pFir;
	*pFir = *pSec;
	return;
}
void GetFirstAndSecond(pTree pTmp,pTree *pFir,pTree *pSec)//得到权值第一第二小的两个未使用节点
{	
		while(NULL != pTmp)
		{
			if(NULL == pTmp->pPar)
			{
				if(pTmp->w <(*pFir)->w)
				{
					(*pSec) = (*pFir);
					(*pFir) = pTmp;
				}
				else if(pTmp->w < (*pSec)->w)
				{
					(*pSec) = pTmp;
				}
			}
			pTmp = pTmp->pNext;
		}
}
void ProdTree(pTree *pTail,pTree pTmp,pTree pFir,pTree pSec)//处理新产生的节点
{		
	pTmp->pLef = pFir;
	pTmp->pRit = pSec;
	pFir->pPar = pTmp;
	pSec->pPar = pTmp;
	pTmp->pNext = NULL;
	pTmp->w = pFir->w+pSec->w;
	(*pTail)->pNext = pTmp;
	*pTail = pTmp;
}

pTree GetTree(pTree pHead)//产生树
{	
	pTree pTmp,pFir,pSec,pSwap,pTail;
	int ret;

	pTmp = pHead->pNext;
	while(NULL != pTmp->pNext)
	{
		pTmp = pTmp->pNext;
	}
	pTail = pTmp;//置尾节点
	do
	{
		pTmp = pHead->pNext;
		pTmp = GetFirstAvaiNode(pTmp);//找到第一个可用节点
		if(NULL == pTmp)
		{
			break;
		}
		pFir = pTmp;//给最小指针赋值
		pTmp = GetFirstAvaiNode(pTmp->pNext);
		if(NULL == pTmp)
		{
			break;
		}
		pSec = pTmp;//给第二小指针赋值
		if(pSec->w < pFir->w)
		{
			Swep(&pSec,&pFir);
		}
		pTmp = pTmp->pNext;
		GetFirstAndSecond(pTmp,&pFir,&pSec);//得到权值第一第二小的两个未使用节点
		ret = CreateNode(&pTmp,'+');
		if(ERR == ret)
		{
			return NULL;
		}
		ProdTree(&pTail,pTmp,pFir,pSec);//产生一个新节点，并插入链表中
	}while(NULL != pSec);
	return pTail;
}

int Fun_Traversal_2(pTree pTreeNodeR)
{//中序遍历
	pTree pTmp = pTreeNodeR;
	int ret=1;

	if(NULL !=pTmp->pLef)
	{
		Fun_Traversal_2(pTmp->pLef);
	}
	printf("\'%c\'(%d)\t",pTmp->c,pTmp->w);
	if(NULL != pTmp->pRit)
	{
		Fun_Traversal_2(pTmp->pRit);
	}
	return SUC;		
}
		








