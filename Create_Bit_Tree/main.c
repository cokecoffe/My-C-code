#include<stdio.h>
#include"main.h"
#include"tree.h"

main()
{
	pData T;
	int index=0;
	 
	printf("--先序建立 \n");
	PreCreateTree(&T);//先序建立二杈树
	
	printf("1--先序遍历 2--中序遍历 3--后序遍历\n");
	scanf("%d",&index);
	while(index!=4)
	{
		switch(index)
		{
			case 1:PreTraverse(T);//先序遍历二杈树
					break;
			case 2:MidTraverse(T);//中序
					break;
			case 3:LastTravers(T);//后序
					break;
			case 4:return;
			default:{
						printf("No selection\n");
						return 0;
					}
		}	
	}
	
}
