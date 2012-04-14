#include<stdio.h>
#include"./str.h"

int str_len(char *str)
{
	int str_len = 0;
	if(NULL==str)
	{
		return ER;
	}
	while(*str++!=0)
	{
		str_len++;
	}
	return str_len;
}
