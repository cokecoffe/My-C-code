#include<stdio.h>
#define NUM 10
main()
{
	int num=0,temp=0,i=0,j=0;
	char num_s[NUM],data[NUM];
	printf("输入一个数：\n");
	scanf("%d",&num);

	if(num>0)
	{
		temp=num;
	}
	else
	{
		temp=-num;
	}

	while(temp!=0)
	{
		num_s[i]=temp%10+48;
		temp=temp/10;
		i++;
	}

	i--;

	if(num>0)
	{
		while(i>=0)
		{
			data[j]=num_s[i];
			i--;
			j++;
		}
	}
	else
	{
		data[j++]='-';
		while(i>=0)
		{
			data[j]=num_s[i];
			i--;
			j++;
		}

	}

	data[j]='\0';
	printf("转化为的字符串为:%s\n",data);

}
