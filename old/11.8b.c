#include<stdio.h>
#include"./malloc/create.h"
#define LEN 10
#define SCH 2
#define CLA 2
#define STU 2

typedef struct student
{
	char *name;
	int score;
}sStu,*pStu;

typedef struct class
{
	sStu *stu_stu;
}sStuCla,*pStuCla;

typedef struct school
{
	sStuCla *stu_class;
}sStuSch,*pStuSch;		

int cla_sum(pStuSch sh,int *cla_score,int *sch_score)
{
	int i=0,j=0,k=0,n=0;
	int sum=0;
	
	int cla_s=0;

	for(i=0;i<SCH;i++)
	{
		for(j=0;j<CLA&&n<4;j++,n++)
		{
			for(k=0;k<STU;k++)
			{
				cla_score[n] += sh[i].stu_class[j].stu_stu[k].score;
			}
			sch_score[i] += cla_score[n];
		}
	}

}
main()
{
	int i=0,j=0,k=0;
	int sch_score[2]={0,0};
	int class_score[4]={0,0,0,0};

	pStuSch sch;
	dynamic_create((void**)(&sch),SCH*sizeof(sStuSch));//开辟学校空间

	for(i=0;i<SCH;i++)
	{
		dynamic_create((void **)(&(sch[i].stu_class)),CLA*sizeof(sStuCla));//开辟班级空间
		
		for(j=0;j<CLA;j++)
		{
			dynamic_create((void **)(&(sch[i].stu_class[j].stu_stu)),STU*sizeof(sStu));//为每个班级创建两个同学
			for(k=0;k<STU;k++)
			{
				printf("i=%d j=%d k=%d\n",i,j,k);
				dynamic_create((void **)(&(sch[i].stu_class[j].stu_stu[k].name)),LEN*sizeof(char));//为每个同学创建名字空间

				printf("输入学生的姓名和分数");
				scanf("%s",sch[i].stu_class[j].stu_stu[k].name);
				scanf("%d",&(sch[i].stu_class[j].stu_stu[k].score));
			}
		}
	}
/*计算每个学校的总成绩*/

	cla_sum(sch,class_score,sch_score);
	for(i=0;i<SCH;i++)
	{
		printf("%d学校总分数为%d\n",i,sch_score[i]);
		
		for(j=0;j<CLA;j++)
		{
			printf("  %d学校%d班级总成绩为:%d",i,j,class_score[j]);
		}
		printf("\n");
	}
}

