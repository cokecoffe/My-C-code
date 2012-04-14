#include<stdio.h>
#include"main.h"
#include"queue.h"

main()
{
	int i=0;
	int ret=0;
	int index = 0;
	int select = 0;
	int in_data;					//存放要入队列的数字
	int out_data;					//出队列的数字
	
	SqQueue Q[NUM_OF_QUE];
	for(i=0;i<NUM_OF_QUE;i++)   //初始化3个队列
	{
		ret = InitQueue(Q+i);
		if(ret!=OK)
		{
			return ER;
		}
	}
	while(index!=EXIT)
	{
		printf("选择进入第几个队列:(3-退出)\n");
		scanf("%d",&index);
		if(index==3)
		{
			return ;
		}
		printf("选择要进行的操作:\n");
		printf("1-入队列 2-出队列 \n");
		scanf("%d",&select);
		switch(select)
		{
			case 1: {
						printf("输入要入队列的数字:\n");
						scanf("%d",&in_data);
						EnQueue(Q+index,in_data);		//入队列
					}
					break;
					
			case 2:	{
						ret = DeQueue(Q+index,&out_data);//出队列
						if(ret != ER)
						{
							printf("%d\n",out_data);
						}
					}
					break;
					
			case EXIT:
					break;
			
			default:break;
		}
	}
}
