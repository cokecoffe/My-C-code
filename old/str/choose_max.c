#include"str.h"

int choose_max(const char *p1,const char *p2,char *p3)
{
	if(NULL==p1||NULL==p2||NULL==p3)
	{
		return ERR;
	}
	while(*p1!='\0'&&*p2!='\0')
	{
		if(*p1>=*p2)
		{
			*p3 = *p1;
		}
		else if(*p1<*p2)
			{
				*p3 = *p2;
			}

			p1++;
			p2++;
			p3++;
			
	}
	return OK;
}
