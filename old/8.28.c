#include<stdio.h>
#define N 10
void input(int arr[],int n)
{
	int i=0;
	do
	{
		printf(" 输入一个成绩：\n");
		scanf("%d",&arr[i]);
		i++;
	}while(i<n&&i>0);
}

int average(int score[],int n)
{
	int i;
	int sum=0;
	for(i=0;i<n;i++)
	{
		sum+=score[i];
	}
	return sum/n;
}

main()
{
	int score[N];
	int avr;
	int i;
	input(score,N);
	avr = average(score,N);
	printf("平均成绩：%d\n",avr);
	printf("低于平均分的成绩为：\n");
	for(i=0;i<N;i++)
	{
		if(score[i]<avr)
		{
			printf("%d\n",score[i]);
		}
	}
}
