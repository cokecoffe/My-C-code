#include"create.h"

int dynamic_create(void **arr,int size)
{
	if(NULL==arr||size<0)
	{
		return ER;
	}
		*arr = (void **)malloc(size);
	return OK;
}
