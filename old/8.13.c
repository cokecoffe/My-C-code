#include<stdio.h>
int fun(int a[],int n)
{
	int i,temp;
	int max = a[0];
	int max2;
	for(i=0;i<n;i++)    //找出最大数，记录下最大位置到temp
	{
		if(a[i]>max)
		{
			max=a[i];
			temp=i;
		}
		else{
			temp=0;
			}
	}
	i=temp;

	if(i-1!=-1)
	{
		max2=a[i-1];
    }
	else if(i+1<n)
		{
			max2=a[i+1];
		}

	printf("max=%d\n",max);
	for(i=0;i<n;i++)
	{
		if(i==temp||a[i]==max)
		{
			;
		}
		else
			if(a[i]>max2)
			{
				max2=a[i];
			}
	}
	return max2;
}

main()
{
	int data[5]={5,5,4,3,0};
	int max_2rd;

	max_2rd = fun(data,5);
	printf("max_2rd=%d\n",max_2rd);
}
