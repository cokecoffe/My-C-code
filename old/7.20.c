#include<stdio.h>
#include<string.h>
main()
{
	char data[20]="acegikmops";
	char c;
	int i=0,j;

	printf("原串是：");
	printf("%s\n",data);
	
	printf("请输入要插入的字符:\n");
	c=getchar();
	
	while(data[i]<c&&i<strlen(data))
	{
		i++;
	}

//	printf("i=%d\n",i);
	for(j=strlen(data);j>=i;j--)
	{
//		printf("j=%d\n",j);
		data[j+1]=data[j];
	}
//	printf("%d\n",i);
	data[i]=c;
	printf("%s\n",data);
}
