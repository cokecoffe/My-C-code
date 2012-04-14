#include<stdio.h>
#include"./malloc/create.h"
#define N 3

typedef struct stu
{
	int stu_id;
	float chinese;
	float math;
	float english;
	float sum;
}STU;

int input(STU s[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("输入第%d个学生学号,语文,数学英语成绩\n",i+1);
		scanf("%d %f %f %f",&(s[i].stu_id),&(s[i].chinese),&(s[i].math),&(s[i].english));
	}
}

int avarage(STU s[],int n,float *ava)
{
	int i;
	float sum=0;

	for(i=0;i<n;i++)
	{
		s[i].sum=s[i].chinese+s[i].english+s[i].math; //每个人的平均成绩
		sum +=( s[i].chinese+s[i].english+s[i].math);		    //累加所有人的成绩
	}
	*ava = sum/n;
}

main()
{
	int i;
	STU data[N];
	float ava=0;

	dynamic_create((void**)data,N*sizeof(STU)); 	
	
	input(data,N);

	avarage(data,N,&ava);
	printf("ava=%f\n",ava);
	printf("低于平均分的学生信息为:\n");
	for(i=0;i<N;i++)
	{
		if(data[i].sum<ava)
		{
			printf("学号=%d,数学:%.2f,语文:%.2f,英语:%.2f\n",data[i].stu_id,data[i].math,data[i].chinese,data[i].english);
		}
	}
}



