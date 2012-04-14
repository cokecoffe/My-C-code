#include<stdio.h>
#include"./malloc/create.h"
#include"./str/str.h"
#include"./input/input.h"

main()
{
	char *a;
	char *b;
	char *c;
	int len_a,len_b;
	int ret;

	do									//输入a数组长度
	{
		printf("input the length of string-a:\n");
		scanf("%d",&len_a);
	}while(len_a<0);
	

	do									//输入b数组长度
	{
		printf("input the length of string-b:\n");
		scanf("%d",&len_b);
	}while(len_b<0);
	getchar();
	/*为三个数组分配内存空间*/
	a = create_arr(len_a+1);            
	if(NULL==a)
	{
		printf("a数组分配空间失败！\n");
		return ERR;
	}
	b = create_arr(len_b+1);

	if(NULL==b)
	{
		printf("b数组分配空间失败！\n");
		return ERR;
	}

	c = create_arr(len_a+len_b+1);
	if(NULL == c)
	{
		printf("c数组分配空间失败！\n");
		return ERR;
	}
	ret = input_str(a,len_a);
	if(ERR==ret)
	{
		printf("a数组初始化失败！\n");
		return ERR;
	}

	ret = input_str(b,len_b);
	if(ERR==ret)
	{
		printf("b数组初始化失败！\n");
		return ERR;
	}
	printf("string a = %s\n",a);
	printf("string b = %s\n",b);

	ret = choose_max(a,b,c);
	if(ERR == ret)
	{
		return ERR;
	}
	printf("C = %s\n",c);
}












