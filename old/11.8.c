#include<stdio.h>
#include"./malloc/create.h"
#include"./input/input.h"
#define N 3


enum if_ok {ok,no};
struct score
{
	int chinese;
	int english;
	int math;
};

typedef struct stu
{
	char *stu_name;
	struct score stu_score;
	int sum;
	int serial;
	enum if_ok ok_no;
}STU;

int input_data(STU *stu,int n)		//成绩录入函数
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("输入姓名\n");
		input_str(stu[i].stu_name,6);
		
			printf("输入chinese成绩\n");
			scanf("%d",&(stu[i].stu_score.chinese));
		
			printf("输入english成绩\n");
			scanf("%d",&(stu[i].stu_score.english));

			printf("输入math成绩\n");
			scanf("%d",&(stu[i].stu_score.math));
	}
}
int score_sum(STU stu[],int num)
{
	int i;
	for(i=0;i<num;i++)
	{
		stu[i].sum = stu[i].stu_score.chinese
					+stu[i].stu_score.english
					+stu[i].stu_score.math;

	}
}

int score_sort(STU *p[],int num)//成绩排序
{
	int i,j;
	STU *tmp;

	for(i=0;i<num-1;i++)
	{
		for(j=0;j<i-1;j++)
		{
			if( p[j]->sum > p[j+1]->sum)
			{
				tmp = p[j];
				p[j] = p[j+1];
				p[j+1]=tmp;
			}
		}
	}
	
}

main()
{
	STU stu[N],*p[N];
	char *name;
	int i;

	dynamic_create((void **)&stu,sizeof(STU));//为结构体开辟空间

	for(i=0;i<N;i++)
	{
		dynamic_create((void **)&name,6*sizeof(STU));//为名字开辟空间
		stu[i].stu_name	= name;
	}	

	for(i=0;i<N;i++)      //为指针数组初始化
	{
		p[i]=&stu[i];
	}

	input_data(stu,N);//输入数据,N为学生人数
	score_sum(stu,N);//求总成绩
	score_sort(p,N);//成绩排序
	
	for(i=0;i<N;i++)      //为指针数组初始化
	{
		printf("NO.%d name=%s\n",i,p[i]->stu_name);

		if(i<(N*7/10))
		{
			p[i]->ok_no=1;
		}
	}
}
