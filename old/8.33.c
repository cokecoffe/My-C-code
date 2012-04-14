#include<stdio.h>
int fun(int n,int arr[])
{
	int temp;// 用于存放取出的各个位的数
	int max;//记录最大数
	int i=0;//记录0的个数
	int max_count = 0;//记录最大数的个数
	int n_1;
	n_1=n;

	while(n>0)
	{
		temp = n%10;
		if(temp==0)
		{
			i++;
		}
		if(temp>max)
		{
			max=temp;
		}
		n=n/10;
	}
	arr[0]=max;

	while(n_1>0)
	{
		if(n_1%10==max)
		{
			max_count++;
		}
		n_1=n_1/10;
	}
	arr[1]=max_count;

	return i;
}

main()
{
	int num;
	int max[2]={-1,-1};
	int ret=0;

	printf("输入一个整数");
	scanf("%d",&num);

	ret = fun(num,max);
	if(ret == -1)
	{
		return -1;
	}

	printf("0的个数为%d，最大数为：%d，个数为：%d\n",ret,max[0],max[1]);

}
