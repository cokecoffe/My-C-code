#include<stdio.h>
#define OK 0
int sum(int n)
{
	int sum;
	if(n<0)
	{	
		n=-n;
	}
	while(n>0)
	{
		sum+=n%10;
		n=n/10;
	}
	return sum;
}
main()
{
	int num;
	int ret;

	printf("输入一个数字：\n");
	scanf("%d",&num);

	ret = sum(num);
	if(-1==ret)
	{
		printf("ERROR\n");
		return -1;
	}
	else
		{
			printf("各位数字之和=%d\n",ret);
		}
}

