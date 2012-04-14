#include<stdio.h>
#include"str.h"

char *str_cpy(char *str1,const char *str2)
{
	
	if(NULL==str1||NULL==str2)
	{
		return NULL;
	}

	if(str_len(str1)>=str_len(str2))
	{
		while(*str2!=0)
		{
			*str1++ = *str2++;
		}
	}
	else
	{
		printf("目的串长度不够!\n");
		return NULL;
	}

}
