#include<stdio.h>
int up_min(int num[][5])
{
	int i,j;
	int min=num[0][1];

	for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				if(i<j)
				{
					if(num[i][j]<min)
					{
						min = num[i][j];
					}
				}
			}
		}
	return min;

}

int down_max(int num[][5])
{

	int i,j;
	int max=num[0][1];

	for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				if(i>j)
				{
					if(num[i][j]>max)
					{
						max = num[i][j];
					}
				}
			}
		}
	return max;
}

int sum_fun(int num[][5])
{
	int i,j;
  	int sum=0;

    for(i=0;i<5;i++)
	{
		sum+=num[i][i];
	}	

	for(i=4,j=0;i>=0;j++,i--)
	{	
			sum+=num[i][j];
	}

	sum-=num[2][2];
	return sum;
}

main()
{
	int min,max,sum;
	int num[5][5]={ 1,2,3,4,5,
					6,7,8,9,10,
					10,11,12,13,14,
					15,16,17,18,19,
					20,21,22,23,24};

	min=up_min(num);
	max=down_max(num);
	sum=sum_fun(num);
	
	printf("min=%d,max=%d,sum=%d",min,max,sum);
	printf("\n");
}
