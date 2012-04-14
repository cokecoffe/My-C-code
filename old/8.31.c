#include<stdio.h>
int fun(int m,int n)
{	
	int i,k;
	int flag=1;
	int sum=0;

	for(i=m;i<=n;i++)
	{
		for(k=i-1;k>1;k--)
		{
			if(i%k==0)
			{
				flag=0;    //如果除了1和本身之外有能被整除的,不是素数
			}
		}
		if(flag!=0)
		{
			sum+=i;
		}
		flag = 1;
	}
	return sum;
}
main()
{
	int m,n,sum;
	do
	{
		printf("输入两个正数:");
		scanf("%d",&m);
		scanf("%d",&n);
	}
	while(n<0||m<0||m>n);

	sum=fun(m,n);
	printf("m~n之间的素数的和为：%d\n",sum);
	
}
