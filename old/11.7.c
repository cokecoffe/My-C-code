#include<stdio.h>
#include<stdlib.h>
#include"./input/input.h"
#define N 3
#define LEN 10
#define OK 1
#define ER -1



typedef struct stu
{
	char *stu_name;
	int age;
}STU;




int memory_create(void **arr,int size)
{
		if(NULL==arr||size<0)
		{
			return ER;
		}
		*arr = (void **)malloc(size);
		return OK;
}

int input(STU *stu,char **name,int num)
{
	int i;
	int len;
	for(i=0;i<num;i++)
	{
		printf("输入名字长度\n");
		scanf("%d",&len);
		getchar();

		memory_create((void **)name+i,len*sizeof(char));// 为名字开辟空间
		
		printf("输入第%d个学生的姓名\n",i);
		input_str(*(name+i),len);

		(stu+i)->stu_name = *(name+i);

		printf("输入第%d个学生的年龄\n",i);
		scanf("%d",&((stu+i)->age));
	}
}

int	find_max(STU *s,int num,int *max)//找年龄最大的学生
{
	int i;
	int max_age = (*s).age;
	for(i=0;i<num;i++)
	{
		if( ((s+i)->age)>max_age)
		{
			max_age = (s+i)->age;
			*max = i;
		}
	}
}

main()
{
	int ret=0;
	int i;
	int max=0;
	STU *s;
	char **name;

	memory_create((void **)&s,N*sizeof(STU));//开辟空间

	memory_create((void **)&name,sizeof(char*));

	input(s,name,N);//初始化
	find_max(s,N,&max);//找年龄最大的学生
	printf("年龄最大的学生的姓名和年龄分别是：%s\t%d\n",(s+max)->stu_name,(s+max)->age);

}
