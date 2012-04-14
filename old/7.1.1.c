#include<stdio.h>
main()
{
	char c,alp[20];
	int i;

	printf("请输入一行字符：");
	for(i=0;(c=getchar())!='\n'&&
				i<19;i++)
		alp[i] = c;
	
	alp[i]='\0';
	printf("字符串为：%s\n",alp);	
}
