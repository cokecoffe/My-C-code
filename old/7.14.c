#include<stdio.h>

void print_arr(int x,int y)
{
	int i,j;
	for(i=0;i<x;i++)
	{	
		for(j=0;j<y;j++)
		{
			if(i<=j)
			{
				printf("1 ");
			}
			else
				{
					printf("%d ",i-j+1);
				}

			if(j==(y-1))
				printf("\n");
		}
	}
}



main()
{
	int i,j;
	printf("输入矩阵的阶数\n");

	do
	{	
		scanf("%d",&i);
	}while(i<=0);
	do
	{	
		scanf("%d",&j);
	}while(j<=0);

	print_arr(i,j);
	printf("\n");
}
