#include<stdio.h>
#define NUM 20
main()
{
	char c,data[NUM];
	int index=0,i=0;
	
	printf("请输入一个字符串：");
	for(i=0;(c=getchar())!='\n';i++)
		data[i]=c;
	
	data[++i]='\0';


	for(index=0;data[index]!='\0';index++)
	{
		if(data[index]=='c')
			{
				i=index;
				while(data[i]!='\0')
				{
					 data[i]=data[i+1];
					 i++;
				}
			index--;		
			}
	}
	printf("处理后的字符串为： %s\n",data);

}
