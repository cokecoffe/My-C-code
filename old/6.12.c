#include<stdio.h>
main()
{
	int sum=0;
	int arr[51];
	int i,j;

	for(i=1,j=0;i<=101;i+=2)//将1-101内的奇数存入arr数组
	{
		arr[j] = i;
		j++;
	}

	for(i=1;i<52;i++)//处理数组内数据
	{
		if(i%2==0)
		{
			sum-=arr[i-1];
		}
		else
		{
			sum+=arr[i-1];
		}
	}

	printf("sum=%d\n ",sum);



}
