#include"str.h"

int in_string(char *str1,char *str2)
{
	if(NULL==str1||NULL==str2)
	{
		return ERR;
	}
	int i=0;
	while(*(str1+i)!='\0')
	{
		if(i%3==0&&i!=0)
		{
			*str2 = ' ';
			str2++;
		}
		*str2 = *(str1+i);
		i++;	
		str2++;
	}
	*str2 = '\0';
	return OK;
}
