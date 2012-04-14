#include<stdio.h>
#define ER -1
#include"./str/str.h"

main()
{
	int len,len2;
	char str[20] = "hello";
	char str2[] = "oooo";
//	char *str = NULL;
	char *p;

	printf("%s\n",str);
	p = str_cat(str,str2);

	printf("%s\n",p);
	printf("%s\n",str);

/*	int if_equal;

	if_equal = str_cmp(str,str2);

	if(if_equal>0)
	{
		printf("str>str2\n");
	}
	else if(if_equal>0)
		{
			printf("str<str2\n");
		}
		else
		{
			printf("str=str2\n");
		}
*/
/*
	len = str_len(str);
	len2= str_len(str2);
	if(len==ER)
	{
		printf("字符串为空!\n");
		return ER;
	}
	printf("len = %d,len2 = %d\n",len,len2);

	if(NULL==str_cpy(str,str2))
	{
		printf("字符串复制失败!\n");
		return ER;
	}
	printf("复制后的串1为:%s\n",str);
*/
}
