#include<stdio.h>
#define NUM 10
main()
{
	int num[NUM];
	int i,max_flag=0,min_flag=0;
	int temp;
	printf("输入%d个数字：\n",NUM);

	for(i=0;i<NUM;i++)
	{
		scanf("%d",&num[i]);

		if(num[i]>num[max_flag])
		{
			max_flag=i;
		}

		if(num[i]<num[min_flag])
		{
			min_flag=i;
		}
	}
	
	if(max_flag==0&&min_flag==NUM-1)//特例:当最大数在最后,最小数在最前时,交换两数即可
	{
			temp = num[max_flag];
			num[max_flag] = num[min_flag];
			num[min_flag] = temp;
	}
	else{
			temp = num[max_flag];
			num[max_flag] = num[NUM-1];
			num[NUM-1] = temp;
			
			temp = num[min_flag];
			num[min_flag] = num[0];
			num[0] = temp;
			
		}
	printf("转化后的数组为：\n");

	for(i=0;i<10;i++)
        {
		printf("%d ",num[i]);
	}
	printf("\n");

}
