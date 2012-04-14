#include<stdio.h>
#include"./str/str.h"

main()
{
	char data[]="abcde";
	
	char *p;
	
	printf("原字符串为：%s\n",data);

	p = change(data);

	printf("反转后的字符串为：%s\n",p);
	
}
