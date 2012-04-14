#include<stdio.h>
#include"./str/str.h"
#define NL 10
#define NUM 3 

enum sex {man,woman};

typedef struct st
{
	char name[NL];
	enum sex sx;
	int score;
}STU;

int input_data(STU *p,int num)//输入学生信息
{
	int i;
	int temp;

	for(i=0;i<num;i++)
	{
		printf("输入第%d个学生的姓名成绩,性别（man-0 woman-1）\n",i+1);
		scanf("%s %d %d",(p+i)->name,&(p[i].score),&temp);
		if(temp == 0)	
		{
			p[i].sx = 0;
		}
		else{
				p[i].sx = 1;
			}
	}
}

STU find_stu(STU data[],int n,char *name)//Find the student
{
	int i;
	for(i=0;i<n;i++)
	{
		if(!str_cmp(name,data[i].name))
		{
			return data[i];
		}
	}
}
int change(STU *n1,STU *n2)//Change the info of student
{
	STU temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
int max_name(STU data[],int n)//find the larger name 
{
	STU *p = data;
	char *max = p->name;
	int i,j=0;

	for(i=0;i<n;i++)
	{
		if(str_cmp((p+i)->name,max)>0)
		{
			max = (p+i)->name;
			j=i;
		}
	}
	return j;
}
int combine(STU n1,STU n2,char *str)//将两个学生信息合并到一个变量中
{
	int i=0,j=0,k=0;
	char *name;
	int score;
	char tmp_score[3]={'0','0','0'};
	int flag = 2;//控制循环次数

	name = n1.name;
	score = n1.score;
	printf("name = %s\n",name);
	printf("score = %d \n",score);

	while(flag>0)
	{	i=0,j=0;
		while(name[i]!='\0')
		{
			str[k]=name[i];
			i++;
			k++;
		}
		while(score!=0)
		{
			tmp_score[j]=(score%10+48);
			score = score/10;
			j++;
		}
		for(j-1;j>=0;j--)
		{
			str[k]=tmp_score[j];
			k++;
		}
		str[k] = '#';
		name = n2.name;
		score = n2.score;
		k++;
		flag--;
	}
	str[k] = '\0';
}


main()
{
	STU data[NUM];
	STU Tmp,Tmp2;
	char name[NL];
	char name2[NL];
	int max=0;
	int i=0,j=0;
	char file[30];
	char f_read[30];//接受从文件读出的内容
	int flag=0;			//相同名字的标记符号	
	FILE *id;

/*输入数据*/
	input_data(data,NUM);


/*交换学生信息*/
/*	printf("输入要交换的两个学生的姓名：\n");
	scanf("%s %s",name,name2);

	Tmp = find_stu(data,NUM,name);
	Tmp2 = find_stu(data,NUM,name2);
	change(&Tmp,&Tmp2);
*/

/*根据姓名查找并输出学生信息*/
/*	printf("输入要查找的学生的姓名：\n");
	scanf("%s",name);

	Tmp = find_stu(data,NUM,name);
	printf("name:%s,score=%d,",Tmp.name,Tmp.score);
	if(Tmp.sx==0)
	{
		printf("sex:man\n");
	}
	else{
			printf("sex:woman\n");
		}
*/		
/*查找姓名最大的学生*/
	max = max_name(data,NUM);
	printf("最大姓名的学生为%s\n",data[max].name);

/*查找姓名LEN相同的学生*/       //    怎样保证输出无重复
printf("姓名长度相同的同学有\n");
	for(i=0;i<NUM-1;i++)
	{
		flag = 0;
		for(j=i+1;j<NUM;j++)
		{
			if(str_len(data[i].name)==str_len(data[j].name))
			{
				if(flag==0)
				{
					printf("%s\n",data[i].name);//参考名字只打印一次
				}
				printf("%s\n",data[j].name);
				flag = 1;//有相同的名字flag = 1;
			}
		}
	}
	
/*合并两个成绩到一个变量*/
	printf("输入要保存的两个学生的姓名：\n");
	scanf("%s %s",name,name2);

	Tmp = find_stu(data,NUM,name);
	Tmp2 = find_stu(data,NUM,name2);
	
	combine(Tmp,Tmp2,file);	
	printf("写入变量:%s\n",file);

	id = fopen("./test.c","w+");
printf("长度%d:\n",str_len(file));	
printf("size=%d:\n",sizeof(file));	

	fwrite(file,30,1,id);
	
	fread(f_read,30,1,id);

	printf("读出的信息为:\n");
	printf("%s\n",f_read);

/*将成绩加密再写入文件*/	
	for(i=0;file[i]!='\0';i++)
	{
		if(file[i]>'0'&&file[i]<'9')
		{
			file[i]=file[i]+17;
		}
	}
	fwrite(file,30,1,id);
	fread(f_read,30,1,id);

	printf("加密后读出的信息为:\n");
	printf("%s\n",f_read);
}
