#include"input.h"


int input(int *p,int num)
{
	int i;
	if(NULL==p)
	{
		return ER;
	}

	printf("input %ds score:\n",num);

	for(i=0;i<num;i++)
	{
		scanf("%d",p+i);
	}
	return OK;
}

int input_str(char *arr,int len)
{
	int i;
	if(NULL == arr||len<0)
	{
		printf("赋值错误\n");
		return ER;
	}

	printf("请输入%d个字符:",len);	
	
	for(i=0;i<len;i++)
	{
		scanf("%c",arr+i);
	}	
	*(arr+i)='\0';

	while(getchar()!='\n')
		;
		//清空缓冲区	
	return OK;
}
