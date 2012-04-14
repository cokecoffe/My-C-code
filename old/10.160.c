#include<stdio.h>
#include"./malloc/create.h"
#include"./input/input.h"
int insert(char *a,char *b,int len_b)
{
	char *max;
	max = a;
	
	while(*a!='\0')//a指向‘\0’,max指向最后一个最大数
	{
		if(*a>*max)
		{
			max = a;
		}
		a++;
	}
	printf("a=%c\n",*a);
	while(*b!='\0')//b指向最后一个元素
	{
		b++;
	}
	b--;
	
	printf("b=%c\n",*b);
	printf("max=%c\n",*max);

	
	while(a!=max)//开始导入数据
	{
		*(a+len_b)=*a;
		if(*a!='\0')
		{
			*a=*b;
			b--;
		}
		a--;
	}
	return OK;
}

main()
{
	char *a;
	char *b;
	int len_a=0,len_b=0;
	int ret;
	do
	{
		printf("输入a字符串的长度：\n");
		scanf("%d",&len_a);
	}while(len_a<=0);
	do
	{
		printf("输入b字符串的长度：\n");
		scanf("%d",&len_b);
	}while(len_b<=0);
	getchar();
/*开辟字符串空间*/
	ret = create_char(&b,len_b+1);
	if(ER==ret)
	{
		printf("创建字符串b失败\n");
		return ER;
	}
	ret = create_char(&a,len_a+len_b+1);
	if(ER==ret)
	{
		printf("创建字符串a失败\n");
		return ER;
	}
/*初始化字符串*/

	ret = input_str(a,len_a);
	if(ER==ret)
	{
		printf("字符串a输入失败\n");
		return ER;
	}
	ret = input_str(b,len_b);
	if(ER==ret)
	{
		printf("字符串b输入失败\n");
		return ER;
	}

	printf("a=%s\n",a);
	printf("b=%s\n",b);


/*将b插入到a字符串中*/
	ret = insert(a,b,len_b);
	if(ret!=OK)
	{
		printf("导入失败\n");
		return ER;
	}


	printf("The string = %s\n",a);


}
