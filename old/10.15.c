#include<stdio.h>
#include"./str/str.h"
#include"./malloc/create.h"
char* find_max(int num,char*p[])
{
	int i;
	int *count_max;
	int max;
	int ret;

	ret = create_int(&count_max,num);
	if(OK!=ret)
	{
		printf("分配空间失败\n");
		return NULL;
	}

	for(i=0;i<num;i++)
	{
		*(count_max+i)=0;
	}
	p++;

	for(i=0;i<num;i++)//统计字符串长度
	{
		*(count_max+i) = str_len(*(p+i));
	}

	for(i=0;i<num;i++)
	{
		printf("%d ",*(count_max+i));
	}
	/*查找最大字符串的位置*/
	max = *count_max;

	for(i=0;i<num;i++)
	{
		if(*(count_max+i)>max)
		{
			max = *(count_max+i);
		}
	}
	printf("i=%d\n",i);

	return *(p+i-1);
}


int main(int args,char *p[])
{
	char *result = find_max(args-1,p);
	printf("%s",result);
	printf("\n");
}





