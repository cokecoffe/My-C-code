#include"str.h"

char *str_cat(char *str1,const char *str2)
{
	while(*str1!=0)
	{
		str1++;
	}
	while(*str2!=0)
	{
		*str1++ = *str2++;
	}
	*str1 = '\0';
	return str1;
}
