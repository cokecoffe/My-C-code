#include<stdio.h>
#include<string.h>
#define M 10
int count(char str[],char c)
{
	int i=0;
	int n=0;
	while(str[i]!='\0')
	{
		if(str[i]==c)
		{
			n++;
		}
		i++;
	}
	return n;
}
void input(char str[],int n)
{
	int i = 0;
	printf("输入字符串,以'#'结尾:\n");
	while((str[i]=getchar())!='#')
		i++;

	getchar();
	str[i]='\0';
}

main()
{
	char c;
	char data[M];
	int c_count;
	input(data,M);
	puts(data);

	printf("请输入要统计的字符:\n");
	scanf("%c",&c);

	c_count = count(data,c);
	printf("%c在此字符串中出现的次数是%d\n",c,c_count);
}
