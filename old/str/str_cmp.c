#include"str.h"

int str_cmp(const char *str1,const char *str2)
{
	if(str1==NULL||str2==NULL)
	{
		return ER;
	}
	for(;*str1==*str2;str1++,str2++)
	{
		if(!*str1)
		{
			return 0;
		}
	}
	return *str1-*str2;
}
