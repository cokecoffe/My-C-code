#include<stdio.h>
#define M 5
void input(int arr[],int n)
{	
	int i;
	printf("请输入%d个数字\n",n);

	for(i=0;i<n;i++)
	{	
		scanf("%d",&arr[i]);
	} 
}
int compare(int arr1[],int arr2[],int x)
{
	int i;
	int greater=0,smaller=0,equal=0;
	for(i=0;i<x;i++)
	{
		if(arr1[i]>arr2[i])
		{
			greater++;
		}
		else if(arr1[i]<arr2[i])
			{
				smaller++;
			}
			else
			{
				equal++;
			}
	}
	
	if(greater>smaller)
	{
		return 2;
	}
	else if(greater<smaller)
		{
			return -2;
		}
		else
		{
			return 0;
		}
}

main()
{
	int data_1[M];
	int data_2[M];
	int ret=0;
	int num;

	input(data_1,M);
	input(data_2,M);

	ret = compare(data_1,data_2,M);

	if( -1 == ret)
	{
		printf("Error\n");
		return -1;
	}
	else if(ret>0)
		 {
			printf("data1>data2\n");
         }
		else if(ret<0)
			{
				printf("data1<data2\n");
			}
			else
			{
				printf("data1=data2\n");		
			}
	

}		
