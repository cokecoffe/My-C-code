#include<stdio.h>
#include"main.h"
#include"list.h"
#include"../malloc/create.h"
#include"sort.h"

main()
{
	int i,j;	
	pData sl;
	pData index[RADIX];
	pData prt;
		
	dynamic_create((void**)&sl,sizeof(Data));//头结点
	sl->next = NULL;
	init_list(sl);			//初始化链表数据
	
	printf("原始数据为: ");

	print_data(sl);

	for(i=0;i<MAX_NUM_OF_KEY;i++)	//基数排序
	{
		Distribute(sl,i,index);
		Collect(sl,i,index);
	}
	printf("排序后的数据为:\n");
	
	print_data(sl);
}



