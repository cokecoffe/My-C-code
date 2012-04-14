#include<stdio.h>
main()
{
	int num[10];
	int max=0,index=0,flag;

	printf("请输入5个数字\n");

	do
	{
		scanf("%d",&num[index]);
		index++;
	}
	while(index<5);

	--index;
	max=num[index];

	while(index>=0)
   	{
		if(num[index]>max)
		{
			max=num[index];
			flag=index;
		}
		index--;
	}
	printf("最大元素为：%d\n",max);


	printf("最大元素位置为：%d\n",flag);

}
