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
