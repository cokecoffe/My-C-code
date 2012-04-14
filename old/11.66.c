#include<stdio.h>
#define N 3

struct score
{
	int chinese;
	int math;
	int english;
};

typedef struct stu
{
	char name[10];
	struct score stu_score;
	int (*p)(struct stu);
	int score;
}STU,*PSTU;

typedef struct fun
{
	int (*stu_score_sum)(struct stu);
	
	int (*print_score_sum)(struct stu);
}FUN;

int sum(struct stu t)//计算每个学生总成绩
{
	t.score = t.stu_score.chinese
				+t.stu_score.math
				+t.stu_score.english;
}

int print_score(struct stu n)//打印每个学生总成绩
{
	printf("sum=%d\n",n.score);	
}
main()
{
	STU data[N];
	STU pstu;
	FUN f;
	int i;
	FILE *id;

	
	id=fopen("./student.dat","w+");//打开文件
	for(i=0;i<N;i++)
	{
		printf("输入第%d名学生姓名,语文，数学，英语成绩\n",i);
		scanf("%s %d %d %d",data[i].name,
							&(data[i].stu_score.chinese),
							&(data[i].stu_score.math),
							&(data[i].stu_score.english));
	}
	
	f.stu_score_sum = sum;
	f.print_score_sum = print_score;

	for(i=0;i<N;i++)			//计算每个人的总成绩
	{
		data[i].p = f.stu_score_sum;
		data[i].p(data[i]);
	}
	

	fwrite(data,sizeof(STU),N,id);//将数据写入文件
	
	fread(pstu,sizeof(STU),N,id);//从文件读出数据

	for(i=0;i<N;i++)
	{
		printf("姓名：%s ",pstu[i].name);
		printf("总分：%d\n",pstu[i].score);
	}
	fclose(id);
}
