#include"str.h"

char* str_cpy(char *str1,char *str2)
{
	if(NULL==str1||NULL==str2)
		{
			return NULL;
		}
	while(*str2!='\0')
	{
		*str1 = *str2;
		str2++;
		str1++;
	}

	*str1 = '\0';
	return str1;
}
